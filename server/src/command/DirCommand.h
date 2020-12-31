#pragma once

#include <command/ICommand.h>
#include <filesystem>

namespace avansync {
    class DirCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync