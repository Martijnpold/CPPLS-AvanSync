#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/DelCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("DelCommand should delete directory correctly", "[DelCommand]") {
    //Setup
    TestConnection conn {};
    ListIO sysIO {};
    std::string fileName {"téstDirectory"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir() + fileName);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName) == true);

    DelCommand delCmd {};
    conn.getIO().writeString(fileName);

    //Execute
    delCmd.execute(sysIO, conn);

    //Test
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName) == false);
    REQUIRE(conn.getIO().readLine().getContent() == "OK");
}

TEST_CASE("DelCommand should give proper error", "[DelCommand]") {
    //Setup
    TestConnection conn {};
    ListIO sysIO {};
    std::string fileName {"testDirectory"};

    TestFileUtil::deleteFile(conn.basedir());
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName) == false);

    DelCommand delCmd {};
    conn.getIO().writeString(fileName);

    //Execute
    delCmd.execute(sysIO, conn);

    //Test
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName) == false);
    REQUIRE(conn.getIO().readLine().getContent() == "Error: No such file or directory");
}