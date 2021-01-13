#include "catch.hpp"

#include <buffer/Line.h>

using namespace avansync;

TEST_CASE("Line content should return string", "[Line]") {
    //Setup
    std::string content {"Test message"};
    Line line {content};

    //Test
    REQUIRE(line.isError() != true);
    REQUIRE(line.getContent() == content);
}

TEST_CASE("Line content should return error", "[Line]") {
    //Setup
    std::string content {"Test Error"};
    std::logic_error error {content};
    Line line {error};

    //Test
    REQUIRE(line.isError() == true);
    REQUIRE(line.getContent() == "Error: " + content);
}