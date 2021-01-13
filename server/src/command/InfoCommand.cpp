#include "InfoCommand.h"

namespace avansync::server {
    void InfoCommand::execute(IO& systemIO, IConnection& connection) const {
        connection.getIO().writeString("AvanSync server 1.0, copyright (c) 2020 Martijn Polderman.");
    }
} // namespace avansync::server