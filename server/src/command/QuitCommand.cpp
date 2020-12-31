#include "QuitCommand.h"

namespace avansync {
    void QuitCommand::execute(const IO& systemIO, const IConnection& connection) const {
        connection.close();
    }
} // namespace avansync