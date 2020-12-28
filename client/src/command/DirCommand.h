#pragma once

#include "../../../base/src/command/ICommand.h"

namespace avansync {
    class DirCommand : public ICommand {
    public:
        void execute(const IO &systemIO, const IConnection &connection) const override;
    };
}