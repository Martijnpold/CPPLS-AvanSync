#pragma once

#include <string>
#include <vector>

namespace avansync {
    class IO {
    public:
        virtual std::string readLine() = 0;

        virtual void writeLine(std::string data) = 0;

        virtual void readFile(std::string path, int bytes) = 0;

        virtual void writeFile(std::string path) = 0;
    };
}