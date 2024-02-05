#include "../../src/classes/hash_table/hash_table.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions, overriding insertions and retrievals") {
  hash_table<std::string, int> table;

  table.insert("abc", 1);
  table.insert("abc", 2);
  table.insert("def", 3);

  REQUIRE(table.retrieve("abc") == 2);
  REQUIRE(table.retrieve("ghi") == std::nullopt);
}

TEST_CASE("checking removals") {
  hash_table<std::string, int> table;

  table.insert("abc", 1);
  table.insert("def", 2);
  table.remove("abc");

  REQUIRE(table.retrieve("abc") == std::nullopt);
  REQUIRE(table.retrieve("def") == 2);
}

TEST_CASE("testing copy constructor") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  hash_table<int, std::string> table2(table);

  for (int i = 1; i <= 3; i++) {
    REQUIRE(table.retrieve(i) == table2.retrieve(i));
  }
}

TEST_CASE("testing operator =") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  hash_table<int, std::string> table2 = table;

  for (int i = 1; i <= 3; i++) {
    REQUIRE(table.retrieve(i) == table2.retrieve(i));
  }
}