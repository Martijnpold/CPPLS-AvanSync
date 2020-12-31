#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;


namespace avansync {
    class FileUtil {
    private:
        inline static std::string HASH_DATE_FORMAT {"%Y-%m-%d %H:%M:%S"};
        inline static char HASH_SPLITTER {'|'};

        static std::vector<std::string> splitHash(const std::string& fileHash);

        template<typename TP> static std::time_t to_time_t(TP tp) {
            using namespace std::chrono;
            auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
            return system_clock::to_time_t(sctp);
        }

    public:
        [[nodiscard]] static std::string generateHash(const fs::directory_entry& file);
        [[nodiscard]] static std::string getTypeFromHash(const std::string& hash);
        [[nodiscard]] static std::string getFileNameFromHash(const std::string& hash);
        [[nodiscard]] static time_t getDateFromHash(const std::string& hash);
        [[nodiscard]] static bool isNewer(const std::string& hash1, const std::string& hash2);
    };
} // namespace avansync