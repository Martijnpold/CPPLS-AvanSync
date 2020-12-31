#include "IO.h"

namespace avansync {
    void IO::writeString(const std::string& data) const {
        writeLine(Line {data});
    }

    void IO::writeException(const std::exception& data) const {
        writeLine(Line {data});
    }
} // namespace avansync