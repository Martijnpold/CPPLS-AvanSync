#include "../util/TestCommand.h"
#include "../util/TestConnection.h"
#include "catch.hpp"

#include <command/CommandRepository.h>

using namespace avansync;

TEST_CASE("Should execute correct command", "[CommandRepository]") {
    //Setup
    std::string commandA {"commandA"};
    std::string stringA {"Test command A"};
    std::string commandB {"commandB"};
    std::string stringB {"Test command B"};

    CommandRepository cr {};
    cr.registerCommand<TestCommand>(commandA, stringA);
    cr.registerCommand<TestCommand>(commandB, stringB);

    TestConnection conn {};
    ListIO sysIO {};

    //Execute
    cr.execute(commandA, sysIO, conn);
    cr.execute(commandB, sysIO, conn);
    cr.execute(commandB, sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == stringA);
    REQUIRE(conn.getIO().readLine().getContent() == stringB);
    REQUIRE(conn.getIO().readLine().getContent() == stringB);

    REQUIRE(sysIO.readLine().getContent() == stringA);
    REQUIRE(sysIO.readLine().getContent() == stringB);
    REQUIRE(sysIO.readLine().getContent() == stringB);
}

TEST_CASE("Should contain correct command", "[CommandRepository]") {
    //Setup
    std::string commandA {"commandA"};
    std::string stringA {"Test command A"};
    std::string commandB {"commandB"};
    std::string stringB {"Test command B"};

    CommandRepository cr {};
    cr.registerCommand<TestCommand>(commandA, stringA);
    cr.registerCommand<TestCommand>(commandB, stringB);

    TestConnection conn {};
    ListIO sysIO {};

    //Test
    REQUIRE(cr.hasCommand(commandA) == true);
    REQUIRE(cr.hasCommand(commandB) == true);
    REQUIRE(cr.hasCommand("NonExistingCommand") == false);
}