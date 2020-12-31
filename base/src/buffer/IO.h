#pragma once

#include <string>
#include <vector>
#include "Line.h"

namespace avansync {
    class IO {
    public:
        virtual ~IO() = default;

        [[nodiscard]] virtual Line readLine() const = 0;

        void writeString(const std::string &data) const;

        void writeException(const std::exception &data) const;

        virtual void writeLine(const Line &data) const = 0;

        virtual void readFile(const std::string &path, int bytes) const = 0;

        virtual void writeFile(const std::string &path) const = 0;
    };
}