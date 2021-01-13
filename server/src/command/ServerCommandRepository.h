#pragma once

#include <command/CommandRepository.h>

namespace avansync::server {
    class ServerCommandRepository : public CommandRepository {
    public:
        ServerCommandRepository();
    };
} // namespace avansync::server