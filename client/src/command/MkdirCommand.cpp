#include "MkdirCommand.h"

namespace avansync {
    void MkdirCommand::execute(const IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("MKDIR");
        connection.getIO().writeLine(systemIO.readLine());
        connection.getIO().writeLine(systemIO.readLine());
        systemIO.writeLine(connection.getIO().readLine());
    }
} // namespace avansync