#include "SystemIO.h"

#include <iostream>
#include <stdexcept>

namespace avansync {
    Line SystemIO::readLine() const {
        std::string req;
        getline(std::cin, req);
        return Line {req};
    }

    void SystemIO::writeLine(const Line& data) const {
        std::cout << data << std::endl;
    }

    void SystemIO::readFile(const std::string& path, int bytes) const {
        throw std::logic_error {"SystemIO cannot read files"};
    }

    void SystemIO::writeFile(const std::string& path) const {
        throw std::logic_error {"SystemIO cannot write files"};
    }
} // namespace avansync