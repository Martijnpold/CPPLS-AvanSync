#include "SyncCommand.h"

#include <algorithm>
#include <buffer/ListIO.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync::client {
    void SyncCommand::execute(IO& systemIO, avansync::IConnection& connection) const {
        int deleted {};
        int updated {};
        evaluateFolder(systemIO, connection, "", deleted, updated);
        systemIO.writeString("Completed Sync (" + std::to_string(updated) + "u/" + std::to_string(deleted) + "d)");
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
        std::transform(remoteOutput.begin(), remoteOutput.end(), std::back_inserter(remoteHashes),
                       [](const Line& line) { return line.getContent(); });

        //Get all local files
        std::vector<fs::directory_entry> localFiles {};
        for (const auto& file : fs::directory_iterator(connection.basedir() + path))
            localFiles.push_back(file);

        //Bundle local hashes
        std::vector<std::string> localHashes {};
        std::transform(localFiles.begin(), localFiles.end(), std::back_inserter(localHashes),
                       [](const fs::directory_entry& file) { return FileUtil::generateHash(file); });

        //Compare remote hashes to local hashes
        std::for_each(remoteHashes.begin(), remoteHashes.end(), [&](const std::string& remoteHash) {
            std::string remoteType = FileUtil::getTypeFromHash(remoteHash);
            std::string remotePath = path + "/" + FileUtil::getFileNameFromHash(remoteHash);

            auto localHash =
                    std::find_if(localHashes.begin(), localHashes.end(), [remoteHash](const std::string& localHash) {
                        return FileUtil::getFileNameFromHash(remoteHash) == FileUtil::getFileNameFromHash(localHash);
                    });

            if (localHash != localHashes.end()) {
                //File does exist locally
                std::string localType = FileUtil::getTypeFromHash(*localHash);

                if (remoteType != localType || FileUtil::isNewer(*localHash, remoteHash)) {
                    //File is different or newer compared to remote
                    if (localType != "D") {
                        ListIO putIO {};
                        putIO.writeString(remotePath);
                        putCommand.execute(putIO, connection);
                        updated++;
                        systemIO.writeString("Updated " + remotePath);
                    } else {
                        evaluateFolder(systemIO, connection, remotePath, deleted, updated);
                        systemIO.writeString("Scanning subdirectory " + remotePath);
                    }
                } else {
                    systemIO.writeString("File " + remotePath + " has no changes");
                }
            } else {
                //File does not exist locally, delete
                ListIO delIO {};
                delIO.writeString(remotePath);
                delCommand.execute(delIO, connection);
                deleted++;
                systemIO.writeString("Deleted file " + remotePath + " for not existing locally");
            }
        });

        //Update files missing on the remote
        std::for_each(localHashes.begin(), localHashes.end(), [&](const std::string& localHash) {
            auto remoteHash =
                    std::find_if(remoteHashes.begin(), remoteHashes.end(), [localHash](const std::string& remoteHash) {
                        return FileUtil::getFileNameFromHash(remoteHash) == FileUtil::getFileNameFromHash(localHash);
                    });
            if (remoteHash == remoteHashes.end()) {
                if (FileUtil::getTypeFromHash(localHash) != "D") {
                    ListIO putIO {};
                    putIO.writeString(path + "/" + FileUtil::getFileNameFromHash(localHash));
                    putCommand.execute(putIO, connection);
                } else {
                    ListIO mkdirIO {};
                    mkdirIO.writeString(path);
                    mkdirIO.writeString(FileUtil::getFileNameFromHash(localHash));
                    mkdirCommand.execute(mkdirIO, connection);
                    evaluateFolder(systemIO, connection, path + "/" + FileUtil::getFileNameFromHash(localHash), deleted,
                                   updated);
                }
                updated++;
                systemIO.writeString("Created " + path + "/" + FileUtil::getFileNameFromHash(localHash));
            }
        });
    }
} // namespace avansync