#include "MkdirCommand.h"

namespace avansync::client {
    void MkdirCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("MKDIR");
        connection.getIO().writeLine(systemIO.readLine());
        connection.getIO().writeLine(systemIO.readLine());
        systemIO.writeLine(connection.getIO().readLine());
    }
} // namespace avansync::client