#include "MkdirCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void MkdirCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::wstring parentPath {connection.basedir() + connection.getIO().readLine().getWContent()};
            std::wstring newPath {connection.getIO().readLine().getWContent()};
            fs::create_directories(parentPath + L"/" + newPath);
            connection.getIO().writeString("OK");
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync