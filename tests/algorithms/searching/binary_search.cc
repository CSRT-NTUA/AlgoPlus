#define CATCH_CONFIG_MAIN
#include "../../../src/algorithms/searching/binary_search.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing binary search") {
  std::vector<int> v = {1, 5, 4, 3, 2, 32, 12};
  REQUIRE(bin_search(v, 0, v.size() - 1, 32) == 5);
  REQUIRE(bin_search(v, 0, v.size() - 1, 123) == -1);
}