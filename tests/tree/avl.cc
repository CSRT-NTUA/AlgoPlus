#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/avl_tree.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions and traversals") {
  avl_tree<int> a1;

  a1.insert(10);
  a1.insert(15);
  a1.insert(4);
  a1.insert(-150);
  std::vector<int> v = {-150, 4, 10, 15};
  std::vector<int> inorder = a1.inorder();
  REQUIRE(v == inorder);
}

TEST_CASE("checking search") {
  avl_tree<std::string> a;
  a.insert("hello");
  a.insert("world");
  a.insert("i'm");
  a.insert("spirosmag");
  REQUIRE(a.search("world") == true);
  REQUIRE(a.search("im") == false);
}

TEST_CASE("checking removals") {
  avl_tree<int> a1;
  a1.insert(10);
  a1.insert(2);
  a1.insert(190);
  a1.insert(-20);
  a1.insert(23);
  a1.remove(190);
  std::vector<int> v = {-20, 2, 10, 23};
  std::vector<int> inorder = a1.inorder();
  REQUIRE(v == inorder);
}

TEST_CASE("checking inorder") {
  avl_tree<char> a2;
  a2.insert('g');
  a2.insert('d');
  a2.insert('w');
  a2.insert('o');
  std::vector<char> _v = {'d', 'g', 'o', 'w'};
  std::vector<char> _inorder = a2.inorder();
  REQUIRE(_v == _inorder);

  avl_tree<std::string> a3;
  a3.insert("hello");
  a3.insert("from");
  a3.insert("mars");
  a3.insert("cheers");
  std::vector<std::string> __v = {"cheers", "from", "hello", "mars"};
  std::vector<std::string> __inorder = a3.inorder();
  REQUIRE(__v == __inorder);
}

TEST_CASE("checking preorder") {
  avl_tree<int> a;
  a.insert(10);
  a.insert(5);
  a.insert(-5);
  a.insert(2);
  std::vector<int> __preorder = {5, -5, 2, 10};
  REQUIRE(a.preorder() == __preorder);
}

TEST_CASE("checking postorder") {
  avl_tree<int> a;
  a.insert(10);
  a.insert(5);
  a.insert(-5);
  a.insert(2);
  std::vector<int> __postorder = {-5, 2, 10, 5};
  REQUIRE(a.postorder() == __postorder);
}

TEST_CASE("testing iterators") {
  avl_tree<int> a({8, 4, 3, 1, 5, 6});
  std::vector<int> els = a.inorder();
  std::vector<int> check;
  for (auto it = a.begin(); it != a.end(); it++) {
    check.push_back(*(it));
  }

  REQUIRE(check == els);

  avl_tree<char> b({'a', 'g', 'd', 'w', 'v', 's'});
  std::vector<char> els2 = b.inorder();
  std::vector<char> check2;
  for (auto it = b.begin(); it != b.end(); it++) {
    check2.push_back(*(it));
  }

  REQUIRE(check2 == els2);
}

TEST_CASE("testing clear function") {
  avl_tree<char> a({'g', 'w', 'h', 'p', 'u'});
  a.clear();
  std::vector<char> v = a.inorder();
  REQUIRE(v.size() == 0);
}
