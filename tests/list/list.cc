#define CATCH_CONFIG_MAIN
#include "../../classes/list/linked_list.h"
#include "../catch2/catch.hpp"

TEST_CASE("testing linked list") {
  // this is an example of a unit test to check if any algo or class works as it
  // should
  linked_list<int> l1({1, 4, 5, 10});
  REQUIRE(l1.search(4) == true);
  REQUIRE(l1.search(150) == false);
}
