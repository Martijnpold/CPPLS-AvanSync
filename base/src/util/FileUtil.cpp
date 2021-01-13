#include "FileUtil.h"

#include <sstream>
#include <util/strptime.h>

namespace avansync {
    std::vector<std::wstring> FileUtil::splitHash(const std::wstring& fileHash) {
        std::wstringstream hashstream {fileHash};
        std::wstring segment;
        std::vector<std::wstring> seglist;

        while (std::getline(hashstream, segment, HASH_SPLITTER)) {
            seglist.push_back(segment);
        }

        return seglist;
    }

    std::wstring FileUtil::generateHash(const fs::directory_entry& file) {
        std::wstringstream hash;
        if (file.is_regular_file())
            hash << L"F";
        if (file.is_directory())
            hash << L"D";
        if (file.is_other())
            hash << L"*";
        hash << HASH_SPLITTER;
        std::wstring name {file.path().filename().wstring()};
        hash << name;
        hash << HASH_SPLITTER;
        std::time_t stamp = to_time_t(file.last_write_time());
        std::tm time = *std::localtime(&stamp);
        hash << std::put_time(&time, std::wstring(HASH_DATE_FORMAT.begin(), HASH_DATE_FORMAT.end()).c_str());
        hash << HASH_SPLITTER;
        if (file.is_regular_file()) {
            hash << file.file_size();
        } else {
            hash << "0";
        }
        return hash.str();
    }

    std::string FileUtil::getTypeFromHash(const std::wstring& hash) {
        auto full {splitHash(hash)[0]};
        return {full.begin(), full.end()};
    }

    std::wstring FileUtil::getFileNameFromHash(const std::wstring& hash) {
        return splitHash(hash)[1];
    }

    time_t FileUtil::getDateFromHash(const std::wstring& hash) {
        struct tm timeDate {};
        auto full {splitHash(hash)[2]};
        std::string part {full.begin(), full.end()};
        strptime(part.c_str(), HASH_DATE_FORMAT.c_str(), &timeDate);
        time_t rawtime {mktime(&timeDate)};
        return rawtime;
    }

    bool FileUtil::isNewer(const std::wstring& hash1, const std::wstring& hash2) {
        return getDateFromHash(hash1) > getDateFromHash(hash2);
    }
} // namespace avansync