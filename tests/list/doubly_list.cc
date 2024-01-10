#define CATCH_CONFIG_MAIN
#include "../../src/classes/list/doubly_linked_list.h"
#include "../catch2/catch.hpp"
#include <string>

// TEST DOES NOT PASS
TEST_CASE("testing push back") {
  doubly_linked_list<int> l1;
  doubly_linked_list<char> l2;
  // doubly_linked_list<std::string> l3;

  l1.push_back(1);
  l1.push_back(4);
  l1.push_back(5);
  std::vector<int> v = {1, 4, 5};
  std::vector<int> elem = l1.elements();
  REQUIRE(v == elem);

  l2.push_back('a');
  l2.push_back('g');
  l2.push_back('s');
  std::vector<char> _v = {'a', 'g', 's'};
  std::vector<char> _elem = l2.elements();
  REQUIRE(_v == _elem);

  // l3.push_back("hello");
  // l3.push_back("from");
  // l3.push_back("mars");
  // std::vector<std::string> __v = {"hello", "from", "mars"};
  // std::vector<std::string> __elem = l3.elements();
  // REQUIRE(__v == __elem);
}

TEST_CASE("testing push front") {
  doubly_linked_list<int> l1;
  doubly_linked_list<char> l2;
  doubly_linked_list<std::string> l3;
  l1.push_front(3);
  l1.push_front(5);
  l1.push_front(10);
  std::vector<int> v = {10, 5, 3};
  std::vector<int> elem = l1.elements();
  REQUIRE(v == elem);

  l2.push_front('a');
  l2.push_front('f');
  l2.push_front('j');
  std::vector<char> _v = {'j', 'f', 'a'};
  std::vector<char> _elem = l2.elements();
  REQUIRE(_v == _elem);

  l3.push_front("hello");
  l3.push_front("from");
  l3.push_front("mars");
  std::vector<std::string> __v = {"mars", "from", "hello"};
  std::vector<std::string> __elem = l3.elements();
  REQUIRE(__v == __elem);
}

TEST_CASE("testing search") {
  doubly_linked_list<int> l1({3, 5, 7, 8});
  doubly_linked_list<char> l2({'a', 'v', 'd'});
  doubly_linked_list<std::string> l3({"hello", "there", "everyone"});

  REQUIRE(l1.search(3) == true);
  REQUIRE(l1.search(9) == false);
  REQUIRE(l2.search('a') == true);
  REQUIRE(l2.search('m') == false);
  REQUIRE(l3.search("hello") == true);
  REQUIRE(l3.search("hellos") == false);
}
