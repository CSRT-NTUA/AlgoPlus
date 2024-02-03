#define CATCH_CONFIG_MAIN
#include "../../../src/algorithms/searching/exponential_search.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing exponential search") {
  std::vector<int> v = {1, 6, 43, 0, 9, 20, 60};
  REQUIRE(exponential_search(v, 6) == 1);
  REQUIRE(exponential_search(v, 60) == 6);
  REQUIRE(exponential_search(v, -10) == -1);
}