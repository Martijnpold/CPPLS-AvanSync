#include "QuitCommand.h"

namespace avansync::server {
    void QuitCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.close();
    }
} // namespace avansync::server