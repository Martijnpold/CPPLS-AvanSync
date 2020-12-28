#pragma once

#include <string>
#include "../buffer/IO.h"

namespace avansync {
    class IConnection {
    public:
        [[nodiscard]] virtual IO& getIO() const = 0;

        virtual void close() = 0;
    };
}