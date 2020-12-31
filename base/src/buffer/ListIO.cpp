#include "ListIO.h"

#include <stdexcept>

namespace avansync {
    Line ListIO::readLine() {
        if (_readLines.empty())
            throw std::logic_error {"No lines to read from listIO"};
        Line l {_readLines[0]};
        _readLines.erase(_readLines.begin());
        return l;
    }

    Line ListIO::getReadLine(int index) const {
        if (_readLines.size() >= index)
            throw std::logic_error {"Index out of range"};
        return _readLines[index];
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

    std::vector<Line> ListIO::getWrittenLines() const {
        return _writeLines;
    }

    std::vector<Line> ListIO::getReadLines() const {
        return _readLines;
    }

    void ListIO::addReadLine(const Line& line) {
        _readLines.push_back(line);
    }

    int ListIO::getWrittenLineCount() const {
        return _writeLines.size();
    }

    int ListIO::getReadLineCount() const {
        return _readLines.size();
    }
} // namespace avansync