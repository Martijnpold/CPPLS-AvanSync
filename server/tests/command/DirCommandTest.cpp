#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/DirCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("DirCommand should print filled directory content correctly", "[DirCommand]") {
    //Setup
    TestConnection conn {};
    ListIO sysIO {};
    std::string dirName {"listDir"};
    std::string fileName1 {"testFile1.txt"};
    std::string fileName2 {"testFile2.txt"};
    std::string fileName3 {"testFile3.txt"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir() + dirName);
    TestFileUtil::createFile(conn.basedir() + dirName + "/" + fileName1, '1', 5);
    TestFileUtil::createFile(conn.basedir() + dirName + "/" + fileName2, '2', 5);
    TestFileUtil::createFile(conn.basedir() + dirName + "/" + fileName3, '3', 5);
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName) == true);

    DirCommand dirCmd {};
    conn.getIO().writeString(dirName);

    //Execute
    dirCmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == "3");
    REQUIRE_NOTHROW(conn.getIO().readLine());
    REQUIRE_NOTHROW(conn.getIO().readLine());
    REQUIRE_NOTHROW(conn.getIO().readLine());
    REQUIRE_THROWS(conn.getIO().readLine());
}

TEST_CASE("DirCommand should give proper error", "[DirCommand]") {
    //Setup
    TestConnection conn {};
    ListIO sysIO {};
    std::string dirName {"listDir"};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir());
    REQUIRE(TestFileUtil::exists(conn.basedir() + dirName) == false);

    DirCommand dirCmd {};
    conn.getIO().writeString(dirName);

    //Execute
    dirCmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == "Error: No such file or directory");
}