#define CATCH_CONFIG_MAIN
#include "../../src/classes/hash_table/hash_table.h"
#include "../catch2/catch.hpp"
#include <list>
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

TEST_CASE("testing iterators") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  std::vector<std::list<std::pair<int, std::string>>> v = {
      {{1, "abc"}}, {{2, "bcd"}}, {{3, "cba"}}};

  auto iter = v.begin();
  for (auto it = table.begin(); it != table.end(); it++) {
    std::list<std::pair<int, std::string>> temp = *(it);
    REQUIRE(*(it) == *(iter));
    iter++;
  }
  std::cout << '\n' << '\n';
  hash_table<int, std::string> t2;
  t2.insert(1, "a");
  t2.insert(2, "b");
  t2.insert(3, "c");
  t2.insert(4, "d");

  std::vector<std::list<std::pair<int, std::string>>> v2 = {
      {{1, "a"}}, {{2, "b"}}, {{3, "c"}}, {{4, "d"}}};

  auto iter2 = v2.begin();
  for (auto it = t2.begin(); it != t2.end(); it++) {
    std::list<std::pair<int, std::string>> temp = *(it);
    REQUIRE(*(it) == *(iter2));
    iter2++;
  }
}