#pragma once

#include "../buffer/IO.h"

#include <string>

namespace avansync {
    class IConnection {
    public:
        virtual ~IConnection() = default;

        [[nodiscard]] virtual IO& getIO() const = 0;

        virtual void close() const = 0;

        [[nodiscard]] virtual bool isOpen() const = 0;
    };
} // namespace avansync