#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/RenCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("RenCommand should rename dir correctly", "[RenCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string dirName1 {"testDór1"};
    std::string dirName2 {"téstDir2"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir());
    TestFileUtil::createDir(conn.basedir() + dirName1);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName1) == true);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName2) == false);

    RenCommand cmd {};
    conn.getIO().writeString(dirName1);
    conn.getIO().writeString(dirName2);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName1) == false);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName2) == true);
    REQUIRE(conn.getIO().readLine().getContent() == "OK");
}

TEST_CASE("RenCommand should rename file correctly", "[RenCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string fileName1 {"testDir1"};
    std::string fileName2 {"testDir2"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir());
    TestFileUtil::createFile(conn.basedir() + fileName1, 't', 5);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName1) == true);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName2) == false);

    RenCommand cmd {};
    conn.getIO().writeString(fileName1);
    conn.getIO().writeString(fileName2);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName1) == false);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName2) == true);
    REQUIRE(conn.getIO().readLine().getContent() == "OK");
}

TEST_CASE("RenCommand should return the right error", "[RenCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string fileName1 {"testDir1"};
    std::string fileName2 {"testDir2"};

    TestFileUtil::deleteFile(conn.basedir());
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName1) == false);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName2) == false);

    RenCommand cmd {};
    conn.getIO().writeString(fileName1);
    conn.getIO().writeString(fileName2);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == "Error: No such file or directory");
}