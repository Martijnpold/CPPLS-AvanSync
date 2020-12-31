#include "StreamIO.h"

#include <filesystem>
#include <fstream>

namespace avansync {
    Line StreamIO::readLine() const {
        std::string data;
        getline(_stream, data);
        data.erase(data.end() - 1);
        return Line {data};
    }

    void StreamIO::writeLine(const Line& data) const {
        _stream << data << LINE_BREAK;
    }

    void StreamIO::readFile(const std::string& path, int bytes) const {
        std::ofstream file {path};
        try {
            std::vector<char> buff(bytes, 0);
            _stream.read(buff.data(), bytes);
            file.write(buff.data(), bytes);
            file.close();
        } catch (...) {
            file.close();
            throw;
        }
    }

    void StreamIO::writeFile(const std::string& path) const {
        uintmax_t fileSize {std::filesystem::file_size(path)};
        std::ifstream file {path};
        try {
            std::vector<char> buff(fileSize, 0);
            file.read(buff.data(), fileSize);
            _stream.write(buff.data(), fileSize);
            file.close();
        } catch (...) {
            file.close();
            throw;
        }
    }
} // namespace avansync