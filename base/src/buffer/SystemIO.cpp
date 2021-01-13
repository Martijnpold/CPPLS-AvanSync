#include "SystemIO.h"

#include <iostream>
#include <stdexcept>

namespace avansync {
    Line SystemIO::readLine() {
        std::wstring req;
        getline(std::wcin, req);
        return Line {req};
    }

    void SystemIO::writeLine(const Line& data) {
        std::wcout << data << std::endl;
    }

    void SystemIO::readFile(const std::wstring& path, int bytes) {
        throw std::logic_error {"SystemIO cannot read files"};
    }

    void SystemIO::writeFile(const std::wstring& path) {
        throw std::logic_error {"SystemIO cannot write files"};
    }
} // namespace avansync