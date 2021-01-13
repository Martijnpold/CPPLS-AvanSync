#pragma once

#include "DelCommand.h"
#include "DirCommand.h"
#include "GetCommand.h"
#include "MkdirCommand.h"
#include "PutCommand.h"

#include <command/ICommand.h>

namespace avansync::client {
    class SyncCommand : public ICommand {
    private:
        DirCommand dirCommand {};
        GetCommand getCommand {};
        DelCommand delCommand {};
        PutCommand putCommand {};
        MkdirCommand mkdirCommand {};

        void evaluateFolder(IO& systemIO, avansync::IConnection& connection, const std::string& path, int& deleted,
                            int& updated) const;

    public:
        void execute(IO& systemIO, IConnection& connection) const override;
    };
} // namespace avansync::client