#pragma once

#include <iostream>
#include "../connection/IConnection.h"

namespace avansync {
    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void execute(const IO& systemIO, const IConnection& connection) const = 0;
    };
}