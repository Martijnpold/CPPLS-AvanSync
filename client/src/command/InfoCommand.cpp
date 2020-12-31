#include "InfoCommand.h"

namespace avansync {
    void InfoCommand::execute(const IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("INFO");
        systemIO.writeLine(connection.getIO().readLine());
    }
} // namespace avansync