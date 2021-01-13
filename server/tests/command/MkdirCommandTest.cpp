#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/MkdirCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("MkdirCommand should make dir correctly", "[MkdirCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string dirName {"téstDir"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir());
    MkdirCommand cmd {};
    conn.getIO().writeString("./");
    conn.getIO().writeString(dirName);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName) == false);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName) == true);
    REQUIRE(conn.getIO().readLine().getContent() == "OK");
}

TEST_CASE("MkdirCommand should throw the proper error", "[MkdirCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string dirName {"testDir"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createFile(conn.basedir() + dirName, 'a', 1);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName) == false);

    MkdirCommand cmd {};
    conn.getIO().writeString("./");
    conn.getIO().writeString(dirName);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
}