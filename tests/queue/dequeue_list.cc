#include "../../src/classes/queue/dequeue_list.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing push") {
  dequeue_list<int> q;
  q.push_front(10);
  q.push_back(20);
  q.push_front(15);
  std::vector<int> v = {15, 10, 20};
  std::vector<int> check;
  for (auto it = q.begin(); it != q.end(); it++) {
    check.push_back(*(it));
  }
  REQUIRE(v == check);

  dequeue_list<std::string> q2({"hello", "there", "world"});
  std::vector<std::string> v2 = {"hello", "there", "world"};
  std::vector<std::string> check2;
  for (auto it = q2.begin(); it != q2.end(); it++) {
    check2.push_back(*(it));
  }
  REQUIRE(check2 == v2);
}

TEST_CASE("testing pop") {
  dequeue_list<int> q;
  q.push_front(10);
  q.push_back(20);
  q.push_front(15);
  q.push_front(35);
  q.push_front(45);
  q.pop_front();
  REQUIRE(q.front() == 35);
  REQUIRE(q.back() == 20);
  q.pop_back();
  REQUIRE(q.back() == 10);
}

TEST_CASE("testing size") {
  dequeue_list<int> q;
  q.push_front(10);
  q.push_back(20);
  q.push_front(15);
  q.push_front(35);
  q.push_front(45);

  REQUIRE(q.size() == 5);
  q.clear();
  q.push_back(10);
  REQUIRE(q.size() == 1);
  q.push_front(20);
  REQUIRE(q.size() == 2);
}
