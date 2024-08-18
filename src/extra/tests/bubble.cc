#define CATCH_CONFIG_MAIN
#include "../../../third_party/catch.hpp"
#include "../containers/bubble.h"
#include <string>
#include <cmath>

TEST_CASE("Testing insertion for bubble class") {
    bubble<int, 5> b;
    b.insert(-10, 0, 10, 40, 50);
    REQUIRE(b.size() == 5);
    REQUIRE(b[0][0] == -10);
    REQUIRE(b[1][0] == 0);
    REQUIRE(b[2][0] == 10);
    REQUIRE(b[3][0] == 40);
    REQUIRE(b[4][0] == 50);
}

TEST_CASE("Testing searching for bubble class") {
    bubble<std::string, 5> b;

    b.insert("a", "c", "i", "l", "y");
    b.insert("because", "bee", "before");
    b.insert("careful", "coconut", "circle");
    b.insert("ker");
    b.insert("normal", "normalize");
    b.insert("wow");
    REQUIRE(b.search("wow") == true);
    REQUIRE(b.search("coconut") == true);
    REQUIRE(b.search("a") == true);
    REQUIRE(b.search("before") == true);
    b.remove("wow");
    REQUIRE(b.search("wow") == false);
    b.remove("before");
    REQUIRE(b.search("before") == false);
    b.remove("c");
    REQUIRE(b.search("c") == false);
}

TEST_CASE("Testing removing for bubble class") {
    bubble<char, 5> b;
    b.insert('a', 'd', 'h', 'k', 'w');
    REQUIRE(b.search('h') == true);
    b.remove('h');
    REQUIRE(b.search('h') == false);
    b.insert('g');
    b.insert('s');
    b.insert('p');
    b.insert('o');
    REQUIRE(b.search('s') == true);
    b.remove('s');
    REQUIRE(b.search('s') == false);

    bubble<int, 5> b2;
    b2.insert(-50, -20, 0, 20, 50);
    b2.insert(35, 30, 38, 36, 45, 22);
    b2.remove(20);
    std::vector v { b2[3] };
    std::vector check {22, 30, 36, 38, 45};
    REQUIRE(v == check);
    b2.remove(35);
    v = b2[3];
    check = {22, 30, 38, 45};
    REQUIRE(v == check);
}

TEST_CASE("Testing size for bubble class") {
    bubble<int, 10> b;
    b.insert(1, 2, 3, 4, 5, 6, 7, 8);
    REQUIRE(b.size() == 8);
    b.remove(1);
    b.remove(2);
    REQUIRE(b.size() == 6);
    b.remove(3, 4, 5, 6, 7, 8);
    REQUIRE(b.size() == 0);
}

TEST_CASE("Testing empty for bubble class") {
    bubble<int, 10> b;
    REQUIRE(b.empty() == true);
    b.insert(10, 20, 30, 40, 50);
    REQUIRE(b.empty() == false);
    b.remove(10, 20, 30, 40, 50);
    REQUIRE(b.empty() == true);
}

TEST_CASE("Testing operator << for bubble class") {
    bubble<int, 5> b;
    b.insert(10, 20, 30, 40, 50, 60, 15, 25, 35, 45);
    CHECK_NOTHROW(std::cout << b << '\n');

    bubble<std::string, 5> b2;
    b2.insert("hello there", "we", "are", "csrt team", "yay!!");
    CHECK_NOTHROW(std::cout << b2 << '\n');
}
