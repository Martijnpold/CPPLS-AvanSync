#pragma once

#include "IO.h"

namespace avansync {
    class SystemIO : public IO {
    public:
        [[nodiscard]] Line readLine() override;

        void writeLine(const Line& data) override;

        void readFile(const std::wstring& path, int bytes) override;

        void writeFile(const std::wstring& path) override;
    };
} // namespace avansync