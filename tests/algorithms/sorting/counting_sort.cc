#include "../../../src/algorithms/sorting/counting_sort.h"
#include "../../catch2/catch.hpp"
#include <vector>

TEST_CASE("Test countingSort function with integer vector") {
    std::vector<int> v = {5, 4, 3, 2, 1};
    countingSort(v);
    REQUIRE(v == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Test countingSort function with an already sorted vector") {
    std::vector<int> v = {1, 2, 3, 4, 5};
    countingSort(v);
    REQUIRE(v == std::vector<int>{1, 2, 3, 4, 5});
}