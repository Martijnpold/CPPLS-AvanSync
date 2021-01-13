#include "PutCommand.h"

#include <filesystem>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void PutCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            connection.getIO().writeString("PUT");
            std::wstring path {systemIO.readLine().getWContent()};
            std::wstring rawPath {connection.basedir() + path};
            uintmax_t fileSize {fs::file_size(rawPath)};

            systemIO.writeString(L"Transmitting " + std::to_wstring(fileSize) + L" bytes " + rawPath);

            connection.getIO().writeString(path);
            connection.getIO().writeString(std::to_string(fileSize));
            connection.getIO().writeFile(rawPath);
            systemIO.writeLine(connection.getIO().readLine());
        } catch (const std::system_error& e) { systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)}); }
    }
} // namespace avansync