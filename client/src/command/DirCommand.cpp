#include "DirCommand.h"

namespace avansync {
    void DirCommand::execute(const IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("DIR");
        connection.getIO().writeLine(systemIO.readLine());

        Line response {connection.getIO().readLine()};
        if (response.isError()) {
            systemIO.writeLine(response);
            return;
        }

        int count = std::stoi(response.getContent());
        for (int i = 0; i < count; i++) {
            systemIO.writeLine(connection.getIO().readLine());
        }
    }
} // namespace avansync