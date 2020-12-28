#include "ServerCommandRepository.h"
#include "InfoCommand.h"
#include "DirCommand.h"

namespace avansync {
    ServerCommandRepository::ServerCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
    }
}