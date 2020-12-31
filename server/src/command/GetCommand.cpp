#include "GetCommand.h"

#include <filesystem>
#include <fstream>
#include <util/ErrorUtil.h>

namespace fs = std::filesystem;

namespace avansync {
    void GetCommand::execute(const IO& systemIO, const IConnection& connection) const {
        try {
            std::ifstream file {connection.getIO().readLine().getContent()};

        } catch (const std::system_error& e) { systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)}); }
    }
} // namespace avansync