#include "DirCommand.h"

#include <util/ErrorUtil.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync::server {
    void DirCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string path {connection.basedir() + connection.getIO().readLine().getContent()};

            std::vector<std::string> hashes {};
            for (const auto& file : fs::directory_iterator(path))
                hashes.push_back(FileUtil::generateHash(file));

            connection.getIO().writeString(std::to_string(hashes.size()));
            for (const auto& hash : hashes)
                connection.getIO().writeString(hash);
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync::server