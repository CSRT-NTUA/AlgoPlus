#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/splay_tree.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing insertion") {
  splay_tree<int> s;
  s.insert(10);
  s.insert(12);
  s.insert(16);
  s.insert(5);
  s.insert(-10);
  s.insert(6);
  std::vector<int> els = s.inorder();
  std::vector<int> check = {-10, 5, 6, 10, 12, 16};
  REQUIRE(els == check);
}

TEST_CASE("testing remove") {
  splay_tree<int> s;
  s.insert(10);
  s.insert(12);
  s.insert(16);
  s.insert(5);
  s.insert(-10);
  s.insert(6);
  REQUIRE(s.search(6) == true);
  REQUIRE(s.search(16) == true);
  REQUIRE(s.search(15) == false);
  s.remove(6);
  REQUIRE(s.search(6) == false);
  s.remove(16);
  REQUIRE(s.search(16) == false);
  s.insert(15);
  REQUIRE(s.search(15) == true);
}

TEST_CASE("testing size") {
  splay_tree<int> s;
  s.insert(10);
  s.insert(12);
  s.insert(16);
  s.insert(5);
  s.insert(-10);
  s.insert(6);
  REQUIRE(s.size() == 6);
  s.remove(10);
  REQUIRE(s.size() == 5);

  splay_tree<std::string> s2(
      {"hello", "there", "universe", "we", "are", "here"});
  REQUIRE(s2.size() == 6);
}

TEST_CASE("testing clear function") {
  splay_tree<int> s;
  s.insert(10);
  s.insert(12);
  s.insert(16);
  s.insert(5);
  s.insert(-10);
  s.insert(6);
  s.clear();
  std::vector<int> els = s.inorder();
  REQUIRE(els.size() == 0);
}
