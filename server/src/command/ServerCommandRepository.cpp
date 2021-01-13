#include "ServerCommandRepository.h"

#include "DelCommand.h"
#include "DirCommand.h"
#include "GetCommand.h"
#include "InfoCommand.h"
#include "MkdirCommand.h"
#include "PutCommand.h"
#include "QuitCommand.h"
#include "RenCommand.h"

namespace avansync::server {
    ServerCommandRepository::ServerCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
        registerCommand<GetCommand>("GET");
        registerCommand<PutCommand>("PUT");
        registerCommand<RenCommand>("REN");
        registerCommand<DelCommand>("DEL");
        registerCommand<MkdirCommand>("MKDIR");
        registerCommand<QuitCommand>("QUIT");
    }
} // namespace avansync