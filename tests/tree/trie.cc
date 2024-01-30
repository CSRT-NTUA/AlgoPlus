#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/trie.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing insertion") {
  trie t;
  t.insert("hello");
  t.insert("world");
  REQUIRE(t.search("hello") == true);
  REQUIRE(t.search("helo") == false);
}

TEST_CASE("testing remove") {
  trie t;
  t.insert("hello");
  t.insert("world");
  t.insert("mars");
  t.insert("universe");
  REQUIRE(t.search("universe") == true);
  t.remove("universe");
  REQUIRE(t.search("universe") == false);
}