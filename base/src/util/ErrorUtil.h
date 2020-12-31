#pragma once

#include <string>
#include <system_error>

namespace avansync {
    class ErrorUtil {
    public:
        static std::string getReason(const std::system_error& e);
    };
} // namespace avansync