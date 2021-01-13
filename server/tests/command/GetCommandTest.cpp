#include "../util/TestConnection.h"
#include "../util/TestFileUtil.h"
#include "catch.hpp"

#include <command/GetCommand.h>

using namespace avansync;
using namespace avansync::server;

TEST_CASE("GetCommand should return file correctly", "[GetCommand]") {
    //Setup
    TestConnection conn {};
    TestIO sysIO {};
    std::string fileName {"testFile"};
    int fileSize {5};

    TestFileUtil::deleteFile(conn.basedir());
    TestFileUtil::createDir(conn.basedir());
    TestFileUtil::createFile(conn.basedir() + fileName, 't', fileSize);
    REQUIRE(TestFileUtil::exists(conn.basedir() + fileName) == true);

    GetCommand cmd {};
    conn.getIO().writeString(fileName);

    //Execute
    cmd.execute(sysIO, conn);

    //Test
    REQUIRE(conn.getIO().readLine().getContent() == std::to_string(fileSize));
    REQUIRE(conn.getIO().fileWritten == conn.basedir() + fileName);
}