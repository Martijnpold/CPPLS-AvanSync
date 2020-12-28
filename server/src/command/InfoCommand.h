#pragma once

#include "../../../base/src/command/ICommand.h"

namespace avansync {
    class InfoCommand : public ICommand {
    public:
        void execute(const IO &systemIO, const IConnection &connection) const override;
    };
}