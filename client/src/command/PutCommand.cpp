#include "PutCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync::client {
    void PutCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            connection.getIO().writeString("PUT");
            std::string path {systemIO.readLine().getContent()};
            std::string rawPath {connection.basedir() + path};
            uintmax_t fileSize {FileUtil::getSize(rawPath)};

            systemIO.writeString("Transmitting " + std::to_string(fileSize) + " bytes " + rawPath);

            connection.getIO().writeString(path);
            connection.getIO().writeString(std::to_string(fileSize));
            connection.getIO().writeFile(rawPath);
            systemIO.writeLine(connection.getIO().readLine());
        } catch (const std::system_error& e) { systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)}); }
    }
} // namespace avansync::client