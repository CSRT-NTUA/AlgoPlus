#include "../../src/classes/hash_table/hash_table.h"
#include "../../third_party/catch.hpp"
#include <list>
#include <string>

TEST_CASE(
    "checking insertions, overriding insertions and retrievals in hash table") {
  hash_table<std::string, int> table;

  table.insert("abc", 1);
  table.insert("abc", 2);
  table.insert("def", 3);

  REQUIRE(table.retrieve("abc") == 2);
  REQUIRE(table.retrieve("ghi") == std::nullopt);
}

TEST_CASE("checking removals in hash table") {
  hash_table<std::string, int> table;

  table.insert("abc", 1);
  table.insert("def", 2);
  table.remove("abc");

  REQUIRE(table.retrieve("abc") == std::nullopt);
  REQUIRE(table.retrieve("def") == 2);
}

TEST_CASE("testing copy constructor in hash table") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  hash_table<int, std::string> table2(table);

  for (int i = 1; i <= 3; i++) {
    REQUIRE(table.retrieve(i) == table2.retrieve(i));
  }
}

TEST_CASE("testing operator = in hash table") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  hash_table<int, std::string> table2 = table;

  for (int i = 1; i <= 3; i++) {
    REQUIRE(table.retrieve(i) == table2.retrieve(i));
  }
}

TEST_CASE("testing iterators in hash table") {
  hash_table<int, std::string> table;
  table.insert(1, "abc");
  table.insert(2, "bcd");
  table.insert(3, "cba");

  std::vector<std::list<std::pair<int, std::string>>> v = {
      {{1, "abc"}}, {{2, "bcd"}}, {{3, "cba"}}};

  // auto iter = v.begin();
  // for (auto it = table.begin(); it != table.end(); it++) {
  //   std::list<std::pair<int, std::string>> temp = *(it);
  //   REQUIRE(*(it) == *(iter));
  //   iter++;
  // }
  std::cout << '\n' << '\n';
  hash_table<int, std::string> t2;
  t2.insert(1, "a");
  t2.insert(2, "b");
  t2.insert(3, "c");
  t2.insert(4, "d");

  std::vector<std::list<std::pair<int, std::string>>> v2 = {
      {{1, "a"}}, {{2, "b"}}, {{3, "c"}}, {{4, "d"}}};

  // auto iter2 = v2.begin();
  // for (auto it = t2.begin(); it != t2.end(); it++) {
  //   std::list<std::pair<int, std::string>> temp = *(it);
  //   REQUIRE(*(it) == *(iter2));
  //   iter2++;
  // }

  hash_table<int, std::string> t3;
  t3.insert(1, "a");
  t3.insert(2, "b");
  t3.insert(3, "c");
  t3.insert(4, "d");

  std::vector<std::list<std::pair<int, std::string>>> v3;
  auto it = t3.begin();
  v3.push_back(*(it));
  it++;
  v3.push_back(*(it));
  it--;
  v3.push_back(*(it));

  // std::vector<std::list<std::pair<int, std::string>>> check_v3 = {
  //     {{1, "a"}}, {{2, "b"}}, {{1, "a"}}};
  // REQUIRE(v3 == check_v3);
}
