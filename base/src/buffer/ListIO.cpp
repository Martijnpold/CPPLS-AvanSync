#include "ListIO.h"

#include <stdexcept>

namespace avansync {
    Line ListIO::readLine() {
        if (_writeLines.empty())
            throw std::logic_error {"No lines to read from listIO"};
        Line l {_writeLines[0]};
        _writeLines.erase(_writeLines.begin());
        return l;
    }

    Line ListIO::getReadLine(int index) const {
        if (_writeLines.size() >= index)
            throw std::logic_error {"Index out of range"};
        return _writeLines[index];
    }

    void ListIO::writeLine(const Line& data) {
        _writeLines.push_back(data);
    }

    void ListIO::readFile(const std::string& path, int bytes) {
        throw std::logic_error {"ListIO cannot read files"};
    }

    void ListIO::writeFile(const std::string& path) {
        throw std::logic_error {"ListIO cannot write files"};
    }

    std::vector<Line> ListIO::getReadLines() const {
        return _writeLines;
    }

    void ListIO::addReadLine(const Line& line) {
        _writeLines.push_back(line);
    }

    int ListIO::getWrittenLineCount() const {
        return _writeLines.size();
    }
} // namespace avansync