#define CATCH_CONFIG_MAIN
#include "../../src/classes/list/skip_list.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing search") {
  skip_list<int> s(3, 0.5);
  s.insert(3);
  s.insert(6);
  s.insert(7);
  s.insert(9);
  s.insert(12);
  s.insert(19);
  s.insert(17);
  s.insert(15);
  s.insert(100);
  s.insert(500);
  s.insert(174);
  s.insert(1234);
  // std::cout << s << '\n';
  REQUIRE(s.search(19) == true);
  REQUIRE(s.search(12) == true);
  REQUIRE(s.search(1234) == true);
}

TEST_CASE("testing deletion") {
  skip_list<char> s(3, 0.5);
  s.insert('a');
  s.insert('b');
  s.insert('d');
  s.insert('r');
  REQUIRE(s.search('b') == true);
  // std::cout << s << '\n';
  s.remove('b');
  // std::cout << s << '\n';
  REQUIRE(s.search('b') == false);
}

TEST_CASE("testing iterators"){
    skip_list<int> s({1, 7, 4, 80, 12, 8, 28, 400});
    std::vector <int> els = s.elements();
    std::vector <int> v;
    for (auto it = s.begin(); it != s.end(); it++){
      v.push_back(*it);
    }
    REQUIRE(els == v);
    
  }