#define CATCH_CONFIG_MAIN
#include "../../../src/algorithms/string/kmp.h"
#include "../../catch2/catch.hpp"
#include <string>

TEST_CASE("testing kmp") {
  std::string a = "ababcabcababababd", b = "ababd";
  REQUIRE(kmp(b, a) == true);
  REQUIRE(kmp("elo", a) == false);
}