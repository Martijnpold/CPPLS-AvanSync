#include "DelCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

namespace avansync::server {
    void DelCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string path {connection.basedir() + connection.getIO().readLine().getContent()};
            int count = fs::remove_all(FileUtil::encodeName(path));
            if (count > 0) {
                connection.getIO().writeString("OK");
            } else {
                connection.getIO().writeString("Error: No such file or directory");
            }
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync::server