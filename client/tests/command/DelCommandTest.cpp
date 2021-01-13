#include "../../src/command/DelCommand.h"

#include "../util/TestConnection.h"
#include "catch.hpp"

using namespace avansync;

TEST_CASE("Should execute correctly", "[DelCommand]") {
    //Setup
    DelCommand delCmd {};

    TestConnection conn {};
    ListIO sysIO {};

    //Execute
    delCmd.execute(sysIO, conn);

    //Test
}