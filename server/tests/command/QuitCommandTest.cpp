#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/QuitCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("QuitCommand should close connection", "[QuitCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    REQUIRE(conn.isOpen() == true);

    QuitCommand cmd {};

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.isOpen() == false);
}