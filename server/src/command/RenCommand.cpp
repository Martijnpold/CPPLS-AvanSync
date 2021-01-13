#include "RenCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync::server {
    void RenCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string oldPath {connection.basedir() + connection.getIO().readLine().getContent()};
            std::string newPath {connection.basedir() + connection.getIO().readLine().getContent()};
            fs::rename(oldPath, newPath);
            connection.getIO().writeString("OK");
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync::server