#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// dokumentacja:   https://github.com/catchorg/Catch2

int adding(int number1, int number2)
{
    return 0;
}

TEST_CASE("Adding0and0")
{
    int number1 = 0;
    int number2 = 0;
    REQUIRE(adding(0, 0) == number1 + number2);
}

TEST_CASE("Adding1and1")
{
    int number1 = 1;
    int number2 = 1;
    REQUIRE(adding(1, 1) == number1+number2);
}
