#include "ServerCommandRepository.h"

#include "DirCommand.h"
#include "InfoCommand.h"

namespace avansync {
    ServerCommandRepository::ServerCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
    }
} // namespace avansync