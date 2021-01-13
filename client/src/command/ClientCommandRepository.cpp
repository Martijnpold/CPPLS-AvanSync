#include "ClientCommandRepository.h"

#include "DelCommand.h"
#include "DirCommand.h"
#include "GetCommand.h"
#include "InfoCommandTest.h"
#include "MkdirCommand.h"
#include "PutCommand.h"
#include "QuitCommand.h"
#include "RenCommand.h"
#include "SyncCommand.h"

namespace avansync::client {
    ClientCommandRepository::ClientCommandRepository() {
        registerCommand<InfoCommand>("INFO");
        registerCommand<DirCommand>("DIR");
        registerCommand<GetCommand>("GET");
        registerCommand<PutCommand>("PUT");
        registerCommand<RenCommand>("REN");
        registerCommand<DelCommand>("DEL");
        registerCommand<MkdirCommand>("MKDIR");
        registerCommand<QuitCommand>("QUIT");
        registerCommand<SyncCommand>("SYNC");
    }
} // namespace avansync