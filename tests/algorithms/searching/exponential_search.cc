#define CATCH_CONFIG_MAIN
#include "../../../src/algorithms/searching/exponential_search.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing exponential search") {
  std::vector<int> v = {1, 15, 60, 100, 150, 300};
  REQUIRE(exponential_search(v, 15) == 1);
  REQUIRE(exponential_search(v, 60) == 2);
  REQUIRE(exponential_search(v, -10) == -1);
}