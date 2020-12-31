#pragma once

#include <command/ICommand.h>

namespace avansync {
    class PutCommand : public ICommand {
    public:
        void execute(const IO& systemIO, const IConnection& connection) const override;
    };
} // namespace avansync