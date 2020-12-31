#include "SystemIO.h"

#include <iostream>
#include <stdexcept>

namespace avansync {
    Line SystemIO::readLine() {
        std::string req;
        getline(std::cin, req);
        return Line {req};
    }

    void SystemIO::writeLine(const Line& data) {
        std::cout << data << std::endl;
    }

    void SystemIO::readFile(const std::string& path, int bytes) {
        throw std::logic_error {"SystemIO cannot read files"};
    }

    void SystemIO::writeFile(const std::string& path) {
        throw std::logic_error {"SystemIO cannot write files"};
    }
} // namespace avansync