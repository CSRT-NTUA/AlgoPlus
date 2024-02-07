#include "../../../src/algorithms/sorting/radix_sort.h"
#include "../../catch2/catch.hpp"
#include <vector>

TEST_CASE("Test radixSort function with integer vector") {
    std::vector<int> v = {170, 45, 75, 90, 24, 2, 66};
    radixSort(v);
    REQUIRE(v == std::vector<int>{2, 24, 45, 66, 75, 90, 170});
}

TEST_CASE("Test radixSort function with an already sorted vector") {
    std::vector<int> v = {2, 24, 45, 66, 75, 90, 170};
    radixSort(v);
    REQUIRE(v == std::vector<int>{2, 24, 45, 66, 75, 90, 170});
}