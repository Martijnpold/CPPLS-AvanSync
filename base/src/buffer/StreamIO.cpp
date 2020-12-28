#include <fstream>
#include <filesystem>
#include "StreamIO.h"

namespace avansync {
    std::string StreamIO::readLine() {
        std::string data;
        getline(_stream, data);
        return data;
    }

    void StreamIO::writeLine(std::string data) {
        _stream.write(data.c_str(), data.length());
    }

    void StreamIO::readFile(std::string path, int bytes) {
        std::ofstream file{path};
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

    void StreamIO::writeFile(std::string path) {
        uintmax_t fileSize{std::filesystem::file_size(path)};
        std::ifstream file{path};
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
}