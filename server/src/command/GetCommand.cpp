#include "GetCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void GetCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string rawPath {"./storage/" + connection.getIO().readLine().getContent()};
            fs::path path {rawPath};
            uintmax_t fileSize {fs::file_size(path)};

            systemIO.writeString("Transmitting " + std::to_string(fileSize) + " bytes " + rawPath);
            connection.getIO().writeString(std::to_string(fileSize));
            connection.getIO().writeFile(rawPath);
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync