#define CATCH_CONFIG_MAIN
#include "../../classes/list/linked_list.h"
#include "../catch2/catch.hpp"

TEST_CASE("testing linked list") {
  linked_list<int> l1({1, 4, 5, 10});
  REQUIRE(l1.search(4) == true);
  REQUIRE(l1.search(150) == false);
}
