#include "DirCommand.h"

namespace avansync {
    void DirCommand::execute(const avansync::IO &systemIO, const avansync::IConnection &connection) const {
        connection.getIO().writeLine("DIR");
        connection.getIO().writeLine(systemIO.readLine());

        int count = std::stoi(connection.getIO().readLine());
        for (int i = 0; i < count; i++) {
            systemIO.writeLine(connection.getIO().readLine());
        }
    }
}