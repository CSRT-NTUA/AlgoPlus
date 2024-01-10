#define CATCH_CONFIG_MAIN
#include "../../classes/list/linked_list.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing search") {
  // this is an example of a unit test to check if any algo or class works as it
  // should
  linked_list<int> l1({1, 4, 5, 10});
  REQUIRE(l1.search(4) == true);
  REQUIRE(l1.search(150) == false);
}

TEST_CASE("testing linked list with strings") {
  std::vector<std::string> __first = {"hello", "world"};
  linked_list<std::string> l1(__first);
  REQUIRE(l1.search("hello") == true);
  l1.push_back("check");
  REQUIRE(l1.search("chec") == false);
}

TEST_CASE("testing linked list with chars") {
  std::vector<char> __first = {'a', 'b', 'c', 'd'};
  linked_list<char> l1(__first);
  l1.erase('b');
  std::vector<char> __second = {'a', 'c', 'd'};
  std::vector<char> elem = l1.elements();
  REQUIRE(elem == __second);
  l1.push_back('g');
  __second.push_back('g');
  elem = l1.elements();
  REQUIRE(elem == __second);
}

TEST_CASE("testing iteration") {
  linked_list<char> l1({'a', 'b', 'c', 'd'});
  std::vector<char> ans = {'a', 'b', 'c', 'd'};
  std::vector<char> elem = l1.elements();
  REQUIRE(elem == ans);
}
