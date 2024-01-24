#define CATCH_CONFIG_MAIN
#include "../../../src/algorithms/string/min_distance.h"
#include "../../catch2/catch.hpp"
#include <string>

TEST_CASE("testing min distance function") {
  std::string a = "hello", b = "world";
  REQUIRE(string::min_dist(a, b) == 4);
  a = "sdasdafda";
  b = "sdasdbbba";
  REQUIRE(string::min_dist(a, b) == 3);

  a = "HellOThere";
  b = "hellothere";
  REQUIRE(string::min_dist(a, b) == 3);
}
