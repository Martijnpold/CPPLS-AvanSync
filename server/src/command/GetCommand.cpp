#include "GetCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync::server {
    void GetCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string rawPath {connection.basedir() + connection.getIO().readLine().getContent()};
            uintmax_t fileSize {fs::file_size(FileUtil::encodeName(rawPath))};

            systemIO.writeString("Transmitting " + std::to_string(fileSize) + " bytes " + rawPath);
            connection.getIO().writeString(std::to_string(fileSize));
            connection.getIO().writeFile(rawPath);
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync::server