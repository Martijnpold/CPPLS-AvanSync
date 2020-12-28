#include "InfoCommand.h"

namespace avansync {
    void InfoCommand::execute(const IO &systemIO, const IConnection &connection) const {
        connection.getIO().writeLine("INFO");
        systemIO.writeLine(connection.getIO().readLine());
    }
}