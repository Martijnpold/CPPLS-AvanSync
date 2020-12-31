#include "SyncCommand.h"

namespace avansync {
    void SyncCommand::execute(IO& systemIO, avansync::IConnection& connection) const {
        evaluateFolder("./storage");
    }

    void SyncCommand::evaluateFolder(std::string path) const {
    }
} // namespace avansync