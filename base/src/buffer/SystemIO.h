#pragma once

#include "IO.h"

namespace avansync {
    class SystemIO : public IO {
    public:
        [[nodiscard]] std::string readLine() const override;

        void writeLine(const std::string &data) const override;

        void readFile(const std::string &path, int bytes) const override;

        void writeFile(const std::string &path) const override;
    };
}