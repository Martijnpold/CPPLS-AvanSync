#include "IO.h"

namespace avansync {
    void IO::writeString(const std::string& data) {
        writeLine(Line {data});
    }

    void IO::writeString(const std::wstring& data) {
        writeLine(Line {data});
    }

    void IO::writeException(const std::exception& data) {
        writeLine(Line {data});
    }
} // namespace avansync