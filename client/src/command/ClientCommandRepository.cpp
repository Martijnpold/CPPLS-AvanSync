#include "ClientCommandRepository.h"
#include "InfoCommand.h"
#include "DirCommand.h"

namespace avansync {
    ClientCommandRepository::ClientCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
    }
}