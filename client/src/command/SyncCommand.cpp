#include "SyncCommand.h"

#include <algorithm>
#include <buffer/ListIO.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void SyncCommand::execute(IO& systemIO, avansync::IConnection& connection) const {
        int deleted {};
        int updated {};
        evaluateFolder(systemIO, connection, "./", deleted, updated);
    }

    void SyncCommand::evaluateFolder(IO& systemIO, avansync::IConnection& connection, const std::string& path,
                                     int& deleted, int& updated) const {
        //Execute DirCommand to fetch remote directory contents
        ListIO remoteDirContents {};
        remoteDirContents.writeString(path);
        dirCommand.execute(remoteDirContents, connection);
        std::vector<Line> remoteOutput {remoteDirContents.getReadLines()};

        //Bundle remote hashes
        std::vector<std::string> remoteHashes {};
        std::transform(remoteOutput.begin() + 1, remoteOutput.end(), std::back_inserter(remoteHashes),
                       [](const Line& line) { return line.getContent(); });

        //Get all local files
        std::vector<fs::directory_entry> localFiles {};
        for (const auto& file : fs::directory_iterator("./storage/" + path))
            localFiles.push_back(file);

        //Bundle local hashes
        std::vector<std::string> localHashes {};
        std::transform(localFiles.begin(), localFiles.end(), std::back_inserter(localHashes),
                       [](const fs::directory_entry& file) { return FileUtil::generateHash(file); });

        //Compare remote hashes to local hashes
        std::for_each(remoteHashes.begin(), remoteHashes.end(), [&](const std::string& remoteHash) {
            std::string remoteType = FileUtil::getTypeFromHash(remoteHash);

            auto localHash =
                    std::find_if(localHashes.begin(), localHashes.end(),
                                 [remoteHash](const std::string& localHash) { return remoteHash == localHash; });

            if (localHash != localHashes.end()) {
                //File does exist locally
                std::string localType = FileUtil::getTypeFromHash(*localHash);

                if (remoteType != localType || FileUtil::isNewer(*localHash, remoteHash)) {
                    //File is different or newer compared to remote
                    if (localType != "D") {
                        ListIO putIO {};
                        putIO.writeString(path + "/" + FileUtil::getFileNameFromHash(remoteHash));
                        putCommand.execute(systemIO, connection);
                        updated++;
                    } else {
                        evaluateFolder(systemIO, connection, path + "/" + FileUtil::getFileNameFromHash(remoteHash),
                                       deleted, updated);
                    }
                }
            } else {
                //File does not exist locally, delete
                ListIO delIO {};
                delIO.writeString(path + "/" + FileUtil::getFileNameFromHash(remoteHash));
                delCommand.execute(delIO, connection);
                deleted++;
            }
        });
    }
} // namespace avansync