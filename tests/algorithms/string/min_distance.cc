#include "../../../src/algorithms/string/edit_distance.h"
#include "../../catch2/catch.hpp"
#include <string>

TEST_CASE("testing min distance function") {
  std::string a = "hello", b = "world";
  REQUIRE(min_dist(a, b) == 4);
  a = "sdasdafda";
  b = "sdasdbbba";
  REQUIRE(min_dist(a, b) == 3);

  a = "HellOThere";
  b = "hellothere";
  REQUIRE(min_dist(a, b) == 3);
}
