#pragma once

#include <string>
#include <vector>

namespace avansync {
    class IO {
    public:
        virtual ~IO() = default;

        [[nodiscard]] virtual std::string readLine() const = 0;

        virtual void writeLine(const std::string &data) const = 0;

        virtual void readFile(const std::string &path, int bytes) const = 0;

        virtual void writeFile(const std::string &path) const = 0;
    };
}