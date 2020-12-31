#include "ErrorUtil.h"

namespace avansync {
    std::string ErrorUtil::getReason(const std::system_error& e) {
        std::error_code ec {e.code()};
        if (ec == std::errc::is_a_directory)
            return "File is a directory";
        if (ec == std::errc::not_a_directory)
            return "Not a directory";
        if (ec == std::errc::no_such_file_or_directory)
            return "No such file";
        if (ec == std::errc::no_space_on_device)
            return "Not enough disk space";
        if (ec == std::errc::read_only_file_system)
            return "Read only filesystem";
        if (ec == std::errc::permission_denied)
            return "No permission";
        return "Unknown: " + std::string {e.what()};
    }
} // namespace avansync