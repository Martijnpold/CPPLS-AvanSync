#include "SystemIO.h"

#include <stdexcept>
#include <iostream>

namespace avansync {
    std::string SystemIO::readLine() const {
        std::string req;
        getline(std::cin, req);
        return req;
    }

    void SystemIO::writeLine(const std::string &data) const {
        std::cout << data << std::endl;
    }

    void SystemIO::readFile(const std::string &path, int bytes) const {
        throw std::logic_error{"SystemIO cannot read files"};
    }

    void SystemIO::writeFile(const std::string &path) const {
        throw std::logic_error{"SystemIO cannot write files"};
    }
}