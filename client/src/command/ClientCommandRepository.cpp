#include "ClientCommandRepository.h"

#include "DirCommand.h"
#include "GetCommand.h"
#include "InfoCommand.h"

namespace avansync {
    ClientCommandRepository::ClientCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
        registerCommand<GetCommand>("GET");
    }
} // namespace avansync