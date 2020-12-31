#include "DelCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void DelCommand::execute(const IO& systemIO, IConnection& connection) const {
        try {
            std::string path {"./storage/" + connection.getIO().readLine().getContent()};
            int count = fs::remove_all(path);
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
} // namespace avansync