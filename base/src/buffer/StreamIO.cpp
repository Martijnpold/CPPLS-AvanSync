#include "StreamIO.h"

#include <filesystem>
#include <fstream>
#include <util/FileUtil.h>

namespace avansync {
    Line StreamIO::readLine() {
        std::string data;
        getline(_stream, data);
        if (data.length() > 0)
            data.erase(data.end() - 1);
        return Line {data};
    }

    void StreamIO::writeLine(const Line& data) {
        _stream << data << LINE_BREAK;
    }

    void StreamIO::readFile(const std::string& path, int bytes) {
        std::filesystem::path fsPath {FileUtil::encodeName(path)};
        if (fsPath.has_parent_path() && !std::filesystem::exists(fsPath.parent_path())) {
            std::filesystem::create_directories(fsPath.parent_path());
        }

        std::ofstream file;
        file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        try {
            file.open(fsPath, std::ofstream::binary | std::ofstream::trunc);
            std::vector<char> buff(bytes, 0);
            _stream.read(buff.data(), bytes);
            file.write(buff.data(), bytes);
            file.close();
        } catch (std::system_error& e) {
            std::string a {e.code().message()};
            std::string b {e.what()};
            file.close();
            throw;
        }
    }

    void StreamIO::writeFile(const std::string& path) {
        std::filesystem::path fsPath {FileUtil::encodeName(path)};
        uintmax_t fileSize {FileUtil::getSize(path)};
        std::ifstream file {fsPath};

        try {
            std::vector<char> buff(fileSize, 0);
            file.read(buff.data(), fileSize);
            _stream.write(buff.data(), fileSize);
            file.close();
        } catch (std::system_error& e) {
            std::string cd {e.code().message()};
            file.close();
            throw;
        }
    }
} // namespace avansync