#include "ClientCommandRepository.h"

#include "DirCommand.h"
#include "InfoCommand.h"

namespace avansync {
    ClientCommandRepository::ClientCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
    }
} // namespace avansync