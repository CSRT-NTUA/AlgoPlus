#include "../../src/classes/stack/stack_list.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing push in stack") {
  stack_list<int> s;
  s.push(10);
  s.push(11);
  s.push(12);
  s.push(13);
  std::vector<int> els = {10, 11, 12, 13};
  reverse(els.begin(), els.end());
  std::vector<int> check;
  for (auto it = s.begin(); it != s.end(); it++) {
    check.push_back(*(it));
  }
  REQUIRE(els == check);

  stack_list<std::string> s2;
  s2.push("world");
  s2.push("hello");
  REQUIRE(s2.top() == "hello");
  s2.pop();
  REQUIRE(s2.top() == "world");
}

TEST_CASE("testing pop in stack") {
  stack_list<int> s;
  s.push(10);
  s.push(11);
  s.push(12);
  s.push(13);
  s.pop();
  REQUIRE(s.top() == 12);
  s.pop();
  REQUIRE(s.top() == 11);
  s.pop();
  REQUIRE(s.top() == 10);
}

TEST_CASE("testing size in stack") {
  stack_list<int> s;
  s.push(10);
  s.push(11);
  s.push(12);
  s.push(13);
  REQUIRE(s.size() == 4);
}
