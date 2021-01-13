#include "RenCommand.h"

namespace avansync::client {
    void RenCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("REN");
        connection.getIO().writeString(systemIO.readLine().getContent());
        connection.getIO().writeString(systemIO.readLine().getContent());
        systemIO.writeLine(connection.getIO().readLine());
    }
} // namespace avansync::client