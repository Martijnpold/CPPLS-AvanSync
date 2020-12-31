#pragma once

#include "../connection/IConnection.h"

#include <iostream>

namespace avansync {
    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void execute(const IO& systemIO, const IConnection& connection) const = 0;
    };
} // namespace avansync