#include "MkdirCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void MkdirCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string parentPath {connection.basedir() + connection.getIO().readLine().getContent()};
            std::string newPath {connection.getIO().readLine().getContent()};
            fs::create_directories(parentPath + "/" + newPath);
            connection.getIO().writeString("OK");
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync