#pragma once

#include <command/ICommand.h>

namespace avansync {
    class RenCommand : public ICommand {
    public:
        void execute(const IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync