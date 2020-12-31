#include "QuitCommand.h"

namespace avansync {
    void QuitCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.close();
    }
} // namespace avansync