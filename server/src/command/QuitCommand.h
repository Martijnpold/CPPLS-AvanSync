#pragma once

#include <command/ICommand.h>

namespace avansync::server {
    class QuitCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync