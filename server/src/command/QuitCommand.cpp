#include "QuitCommand.h"

namespace avansync {
    void QuitCommand::execute(const IO& systemIO, IConnection& connection) const {
        connection.close();
    }
} // namespace avansync