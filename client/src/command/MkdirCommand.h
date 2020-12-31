#pragma once

#include <command/ICommand.h>

namespace avansync {
    class MkdirCommand : public ICommand {
    public:
        void execute(const IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync