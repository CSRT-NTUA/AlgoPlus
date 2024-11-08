#include "../../../src/algorithms/number_theory/mersenne_primes.h"
#include "../../../third_party/catch.hpp"

TEST_CASE("Testing mersenne primes [1]") {
    std::vector<int64_t> m = mersenne(10);
    std::vector<int64_t> check = {2, 3};

    REQUIRE(check == m);
}

TEST_CASE("Testing big mersennse primes [1]") {
    std::vector<int64_t> m = mersenne(1000);
    std::vector<int64_t> check = {2, 3, 5, 7};

    REQUIRE(m == check);
}
