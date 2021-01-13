#include "GetCommand.h"

#include <util/ErrorUtil.h>

namespace avansync {
    void GetCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            connection.getIO().writeString("GET");
            std::wstring path {systemIO.readLine().getWContent()};
            connection.getIO().writeString(path);

            Line response {connection.getIO().readLine()};
            if (response.isError()) {
                systemIO.writeLine(response);
                return;
            }

            int fileSize = std::stoi(response.getContent());
            systemIO.writeString(L"Saving " + std::to_wstring(fileSize) + L" bytes " + connection.basedir() + path);
            connection.getIO().readFile({connection.basedir() + path}, fileSize);
        } catch (const std::system_error& e) { systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)}); }
    }
} // namespace avansync