#include "QuitCommand.h"

namespace avansync::client {
    void QuitCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("QUIT");
        connection.close();
    }
} // namespace avansync::client