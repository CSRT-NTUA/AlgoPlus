#include "../../../src/algorithms/number_theory/eratosthenes_sieve.h"
#include "../../../third_party/catch.hpp"

TEST_CASE("Testing eratosthenes sieve [1]") {
    std::vector<bool> v = soe(10);

    REQUIRE(v[3] == true);
    REQUIRE(v[7] == true);
    REQUIRE(v[6] == false);
}

TEST_CASE("Testing eratosthenes sieve for large numbers [1]") {
    std::vector<bool> v = soe(1000000);

    REQUIRE(v[7237] == true);
    REQUIRE(v[7349] == true);
    REQUIRE(v[7236] == false);
}
