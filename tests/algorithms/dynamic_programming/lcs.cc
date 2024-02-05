#include "../../../src/algorithms/dynamic_programming/lcs.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing longest common subsequence") {
  std::string a = "AGGTAB", b = "GXTXAYB";
  REQUIRE(lcs(a, b) == 4);
  a = "BD";
  b = "ABCD";
  REQUIRE(lcs(a, b) == 2);
}