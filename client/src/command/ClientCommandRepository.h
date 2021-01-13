#pragma once

#include <command/CommandRepository.h>

namespace avansync::client {
    class ClientCommandRepository : public CommandRepository {
    public:
        ClientCommandRepository();
    };
} // namespace avansync::client