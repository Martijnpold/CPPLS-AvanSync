#include "InfoCommand.h"

namespace avansync {
    void InfoCommand::execute(const avansync::IO &systemIO, const avansync::IConnection &connection) const {
        connection.getIO().writeString("AvanSync server 1.0, copyright (c) 2020 Martijn Polderman.");
    }
}