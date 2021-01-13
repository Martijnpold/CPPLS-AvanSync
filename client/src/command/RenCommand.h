#pragma once

#include <command/ICommand.h>

namespace avansync::client {
    class RenCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync::client