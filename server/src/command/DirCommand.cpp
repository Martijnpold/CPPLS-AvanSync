#include "DirCommand.h"

namespace avansync {
    void DirCommand::execute(const avansync::IO &systemIO, const avansync::IConnection &connection) const {
        std::string path{connection.getIO().readLine()};

        std::vector<std::string> hashes{};
        for (const auto &file : std::filesystem::directory_iterator(path)) hashes.push_back(toHash(file));

        connection.getIO().writeLine(std::to_string(hashes.size()));
        for (const auto &hash : hashes) connection.getIO().writeLine(hash);
    }

    std::string DirCommand::toHash(const std::filesystem::directory_entry &file) const {
        std::stringstream hash;
        if (file.is_regular_file()) hash << "F";
        if (file.is_directory()) hash << "D";
        if (file.is_other()) hash << "*";
        hash << "|";
        std::string name{file.path().filename()};
        hash << name;
        hash << "|";
        std::time_t stamp = to_time_t(file.last_write_time());
        std::tm time = *std::localtime(&stamp);
        hash << std::put_time(&time, "%Y-%m-%d %H:%M:%S");
        hash << "|";
        if (file.is_regular_file()) {
            hash << file.file_size();
        } else {
            hash << "0";
        }
        return hash.str();
    }
}