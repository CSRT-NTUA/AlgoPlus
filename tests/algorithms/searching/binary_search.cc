#include "../../../src/algorithms/searching/binary_search.h"
#include "../../../third_party/catch.hpp"

TEST_CASE("testing binary search") {
  std::vector<int> v = {-10, 10, 20, 30, 100};
  REQUIRE(bin_search(v, 0, v.size() - 1, -10) == 0);
  REQUIRE(bin_search(v, 0, v.size() - 1, 30) == 3);
  REQUIRE(bin_search(v, 0, v.size() - 1, -20) == -1);
}

TEST_CASE("testing lower_bound search") {
  std::vector<int> v = {10, 10, 20, 30, 30, 30, 30, 100};
  REQUIRE(lower_bound(v, 0, v.size() - 1, 10) == 0);
  REQUIRE(lower_bound(v, 0, v.size() - 1, 30) == 3);
  REQUIRE(lower_bound(v, 0, v.size() - 1, -20) == -1);
}


TEST_CASE("testing upper_bound search") {
  std::vector<int> v = {10, 10, 20, 30, 30, 30, 30, 100};
  REQUIRE(upper_bound(v, 0, v.size() - 1, 10) == 1);
  REQUIRE(upper_bound(v, 0, v.size() - 1, 30) == 6);
  REQUIRE(upper_bound(v, 0, v.size() - 1, -20) == -1);
}