#include "DelCommand.h"

namespace avansync {
    void DelCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("DEL");
        connection.getIO().writeString(systemIO.readLine().getContent());
        systemIO.writeLine(connection.getIO().readLine());
    }
} // namespace avansync