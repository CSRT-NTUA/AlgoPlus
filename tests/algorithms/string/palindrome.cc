#include "../../../src/algorithms/string/palindrome.h"
#include "../../../third_party/catch.hpp"
#include <string>
#include <vector>

TEST_CASE("Testing palindrome function") {
    std::string str = "abba";
    REQUIRE(is_palindrome(str) == true);
    REQUIRE(is_palindrome("aabbccbbaa") == true);
    REQUIRE(is_palindrome("csrt") == false);
    REQUIRE(is_palindrome("w") == true);
}
