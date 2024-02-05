#include "../../../src/algorithms/sorting/bubble_sort.h"
#include "../../catch2/catch.hpp"
#include <random>
#include <vector>

TEST_CASE("testing merge sort") {
    std::vector<int64_t> v;
    for (int i = 0; i < 5000; i++) {
        int random = rand() % 50000;
        v.push_back(i - random);
    }
    bubble_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()) == true);
}
