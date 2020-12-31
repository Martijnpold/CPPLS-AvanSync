#include "ServerCommandRepository.h"

#include "DirCommand.h"
#include "GetCommand.h"
#include "InfoCommand.h"
#include "PutCommand.h"

namespace avansync {
    ServerCommandRepository::ServerCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
        registerCommand<GetCommand>("GET");
        registerCommand<PutCommand>("PUT");
    }
} // namespace avansync