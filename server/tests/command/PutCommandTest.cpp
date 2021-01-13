#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/PutCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("PutCommand should return info correctly", "[PutCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string fileName {"testFile"};
    int fileSize {5};

    PutCommand cmd {};
    conn.getIO().writeString(fileName);
    conn.getIO().writeString(std::to_string(fileSize));

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().fileRead == conn.basedir() + fileName);
    REQUIRE(conn.getIO().readSize == fileSize);
    REQUIRE(conn.getIO().readLine().getContent() == "OK");
}