#include "../../../src/algorithms/searching/binary_search.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing binary search") {
  std::vector<int> v = {-10, 10, 20, 30, 100};
  REQUIRE(bin_search(v, 0, v.size() - 1, -10) == 0);
  REQUIRE(bin_search(v, 0, v.size() - 1, 30) == 3);
  REQUIRE(bin_search(v, 0, v.size() - 1, -20) == -1);
}