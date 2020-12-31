#pragma once

#include "ICommand.h"

#include <map>
#include <memory>

namespace avansync {
    class CommandRepository {
    private:
        std::map<std::string, std::unique_ptr<ICommand>> _commands;

    public:
        template<typename Command, typename... Args>
        void registerCommand(const std::string& command, const Args&&... args) {
            _commands[command] = std::make_unique<Command>(args...);
        }

        [[nodiscard]] bool hasCommand(const std::string& command) const;

        void execute(const std::string& command, IO& systemIO, IConnection& connection);
    };
} // namespace avansync