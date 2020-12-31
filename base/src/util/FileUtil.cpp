#include "FileUtil.h"

namespace avansync {
    std::vector<std::string> FileUtil::splitHash(const std::string& fileHash) {
        std::stringstream hashstream {fileHash};
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(hashstream, segment, HASH_SPLITTER)) {
            seglist.push_back(segment);
        }

        return seglist;
    }

    std::string FileUtil::generateHash(const fs::directory_entry& file) {
        std::stringstream hash;
        if (file.is_regular_file())
            hash << "F";
        if (file.is_directory())
            hash << "D";
        if (file.is_other())
            hash << "*";
        hash << HASH_SPLITTER;
        std::string name {file.path().filename()};
        hash << name;
        hash << HASH_SPLITTER;
        std::time_t stamp = to_time_t(file.last_write_time());
        std::tm time = *std::localtime(&stamp);
        hash << std::put_time(&time, HASH_DATE_FORMAT.c_str());
        hash << HASH_SPLITTER;
        if (file.is_regular_file()) {
            hash << file.file_size();
        } else {
            hash << "0";
        }
        return hash.str();
    }

    std::string FileUtil::getTypeFromHash(const std::string& hash) {
        return splitHash(hash)[0];
    }

    std::string FileUtil::getFileNameFromHash(const std::string& hash) {
        return splitHash(hash)[1];
    }

    time_t FileUtil::getDateFromHash(const std::string& hash) {
        struct tm timeDate {};
        strptime(splitHash(hash)[2].c_str(), HASH_DATE_FORMAT.c_str(), &timeDate);
        time_t rawtime {mktime(&timeDate)};
        return rawtime;
    }

    bool FileUtil::isNewer(const std::string& hash1, const std::string& hash2) {
        return getDateFromHash(hash1) > getDateFromHash(hash2);
    }
} // namespace avansync