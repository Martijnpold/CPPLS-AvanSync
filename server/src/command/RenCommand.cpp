#include "RenCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void RenCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::wstring oldPath {connection.basedir() + connection.getIO().readLine().getWContent()};
            std::wstring newPath {connection.basedir() + connection.getIO().readLine().getWContent()};
            fs::rename(oldPath, newPath);
            connection.getIO().writeString("OK");
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync