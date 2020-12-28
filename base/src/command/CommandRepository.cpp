#include "CommandRepository.h"

namespace avansync {
    bool CommandRepository::hasCommand(const std::string &command) const {
        return _commands.find(command) != _commands.end();
    }

    void CommandRepository::execute(const std::string &command, const IO &systemIO, const IConnection &connection) {
        if (hasCommand(command)) {
            _commands[command]->execute(systemIO, connection);
        }
    }
}