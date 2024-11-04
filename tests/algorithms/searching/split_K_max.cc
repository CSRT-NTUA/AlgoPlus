#include "../../../src/algorithms/searching/split_K_max.h"
#include "../../../third_party/catch.hpp"

TEST_CASE("Testing split_K_max [1]") {
    std::vector<int> v = {1, 2, 3, 4};

    REQUIRE(minimum_max_sub_sum(v, 3) == 4);
    REQUIRE(minimum_max_sub_sum(v, 2) == 6);
}

TEST_CASE("Testing split_K_max [2]") {
    std::vector<int> v = {2, 6, 1, 13, 3};

    REQUIRE(minimum_max_sub_sum(v, 2) == 16);
    REQUIRE(minimum_max_sub_sum(v, 3) == 13);
    REQUIRE(minimum_max_sub_sum(v, 4) == 13);
}
