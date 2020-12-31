#pragma once

#include <command/ICommand.h>

namespace avansync {
    class PutCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync