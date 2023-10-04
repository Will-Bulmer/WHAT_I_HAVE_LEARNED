#include "catch.hpp"
#include "factorial.h"

int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

TEST_CASE("Factorial is computed", "[factorial]") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(4) == 24);
}
