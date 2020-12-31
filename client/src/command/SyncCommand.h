#pragma once

#include <command/ICommand.h>
namespace avansync {
    class SyncCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;

        void evaluateFolder(std::string path) const;
    };
} // namespace avansync