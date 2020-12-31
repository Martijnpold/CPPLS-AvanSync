#include "InfoCommand.h"

namespace avansync {
    void InfoCommand::execute(const IO &systemIO, const IConnection &connection) const {
        connection.getIO().writeString("AvanSync server 1.0, copyright (c) 2020 Martijn Polderman.");
    }
}