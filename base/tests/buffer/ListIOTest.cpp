#include "catch.hpp"

#include <buffer/ListIO.h>

using namespace avansync;

TEST_CASE("Line read should be equal to written line", "[ListIO]") {
    //Setup
    std::string content {"Test message"};
    Line line {content};
    ListIO io {};

    //Execute
    io.writeLine(line);

    //Test
    Line lineRead {io.readLine()};
    REQUIRE(lineRead.getContent() == line.getContent());
    REQUIRE(lineRead.isError() == false);
}

TEST_CASE("String read should be equal to written line", "[ListIO]") {
    //Setup
    std::string content {"Test message"};
    Line line {content};
    ListIO io {};

    //Execute
    io.writeString(content);

    //Test
    Line lineRead {io.readLine()};
    REQUIRE(lineRead.getContent() == line.getContent());
    REQUIRE(lineRead.isError() == false);
}

TEST_CASE("Exception read should be equal to written line", "[ListIO]") {
    //Setup
    std::string content {"Test message"};
    std::logic_error error {content};
    Line line {error};
    ListIO io {};

    //Execute
    io.writeException(error);

    //Test
    Line lineRead {io.readLine()};
    REQUIRE(lineRead.getContent() == line.getContent());
    REQUIRE(lineRead.isError() == true);
}

TEST_CASE("Writes should read in equal order", "[ListIO]") {
    //Setup
    std::string a {"Test message A"};
    std::string b {"Test message B"};
    std::string c {"Test message C"};
    ListIO io {};

    //Execute
    io.writeString(a);
    io.writeString(b);
    io.writeString(a);
    io.writeString(c);

    //Test
    REQUIRE(io.readLine().getContent() == a);
    REQUIRE(io.readLine().getContent() == b);
    REQUIRE(io.readLine().getContent() == a);
    REQUIRE(io.readLine().getContent() == c);
}