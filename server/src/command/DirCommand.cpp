#include "DirCommand.h"

#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void DirCommand::execute(const IO& systemIO, const IConnection& connection) const {
        try {
            std::string path {"./storage/" + connection.getIO().readLine().getContent()};

            std::vector<std::string> hashes {};
            for (const auto& file : fs::directory_iterator(path))
                hashes.push_back(toHash(file));

            connection.getIO().writeString(std::to_string(hashes.size()));
            for (const auto& hash : hashes)
                connection.getIO().writeString(hash);
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }

    std::string DirCommand::toHash(const fs::directory_entry& file) const {
        std::stringstream hash;
        if (file.is_regular_file())
            hash << "F";
        if (file.is_directory())
            hash << "D";
        if (file.is_other())
            hash << "*";
        hash << "|";
        std::string name {file.path().filename()};
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
} // namespace avansync