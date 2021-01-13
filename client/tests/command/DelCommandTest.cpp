#include "../../src/command/DelCommand.h"

#include "../util/TestConnection.h"
#include "catch.hpp"

#include <command/CommandRepository.h>

using namespace avansync;

TEST_CASE("Should execute correctly", "[DelCommand]") {
    //Setup
    DelCommand delCmd {};

    TestConnection conn {};
    ListIO sysIO {};

    //Execute
//    delCmd.execute();

    //Test
}