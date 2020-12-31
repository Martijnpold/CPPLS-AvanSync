#include "GetCommand.h"

#include <util/ErrorUtil.h>

namespace avansync {
    void GetCommand::execute(const IO& systemIO, const IConnection& connection) const {
        try {
            connection.getIO().writeString("GET");
            std::string path {systemIO.readLine().getContent()};
            connection.getIO().writeString(path);

            Line response {connection.getIO().readLine()};
            if (response.isError()) {
                systemIO.writeLine(response);
                return;
            }

            int count = std::stoi(response.getContent());
            connection.getIO().readFile({"./storage/" + path}, count);
        } catch (const std::system_error& e) { systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)}); }
    }
} // namespace avansync