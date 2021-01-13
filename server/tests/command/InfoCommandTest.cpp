#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/InfoCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("InfoCommand should return info correctly", "[InfoCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};

    InfoCommand cmd {};

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == "AvanSync server 1.0, copyright (c) 2020 Martijn Polderman.");
}