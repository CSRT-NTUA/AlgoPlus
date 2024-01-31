#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/bst.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions and traversals") {
  bst<int> b1;

  b1.insert(2);
  b1.insert(19);
  b1.insert(5);

  std::vector<int> v = {2, 5, 19};
  std::vector<int> inorder = b1.inorder();
  REQUIRE(v == inorder);
}

TEST_CASE("checking removals") {
  bst<int> b1;
  b1.insert(10);
  b1.insert(2);
  b1.insert(190);
  b1.insert(-20);
  b1.insert(23);

  b1.remove(190);
  std::vector<int> v = {-20, 2, 10, 23};
  std::vector<int> inorder = b1.inorder();
  REQUIRE(v == inorder);
}

TEST_CASE("checking search") {
  bst<int> b;
  b.insert(1);
  b.insert(10);
  b.insert(-5);
  b.insert(8);
  REQUIRE(b.search(-5) == true);
  REQUIRE(b.search(-8) == false);

  bst<std::string> b1;
  b1.insert("hello");
  b1.insert("i'm");
  b1.insert("spiros");
  b1.insert("maggioros");
  REQUIRE(b1.search("spiros") == true);
  REQUIRE(b1.search("im") == false);
}

TEST_CASE("checking inorder") {
  bst<char> b2;
  b2.insert('g');
  b2.insert('k');
  b2.insert('a');

  std::vector<char> _v = {'a', 'g', 'k'};
  std::vector<char> _inorder = b2.inorder();
  REQUIRE(_v == _inorder);

  bst<std::string> b3;
  b3.insert("hello");
  b3.insert("abraham");
  b3.insert("cheers");
  std::vector<std::string> __v = {"abraham", "cheers", "hello"};
  std::vector<std::string> __inorder = b3.inorder();
  REQUIRE(__v == __inorder);
}

TEST_CASE("checking preorder") {
  bst<char> b;
  b.insert('g');
  b.insert('a');
  b.insert('b');
  b.insert('w');
  std::vector<char> pre = {'g', 'a', 'b', 'w'};
  REQUIRE(b.preorder() == pre);
}

TEST_CASE("checking postorder") {
  bst<char> b;
  b.insert('g');
  b.insert('a');
  b.insert('b');
  b.insert('w');
  std::vector<char> post = {'b', 'a', 'w', 'g'};
  REQUIRE(b.postorder() == post);
}
