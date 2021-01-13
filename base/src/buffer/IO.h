#pragma once

#include "Line.h"

#include <string>
#include <vector>

namespace avansync {
    class IO {
    public:
        virtual ~IO() = default;

        [[nodiscard]] virtual Line readLine() = 0;

        void writeString(const std::string& data);

        void writeString(const std::wstring& data);

        void writeException(const std::exception& data);

        virtual void writeLine(const Line& data) = 0;

        virtual void readFile(const std::wstring& path, int bytes) = 0;

        virtual void writeFile(const std::wstring& path) = 0;
    };
} // namespace avansync