#include "QuitCommand.h"

namespace avansync {
    void QuitCommand::execute(const IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("QUIT");
        connection.close();
    }
} // namespace avansync