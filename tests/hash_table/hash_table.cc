#define CATCH_CONFIG_MAIN
#include "../../src/classes/hash_table/hash_table.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions, overriding insertions and retrievals") {
    hash_table<int, std::string> table;

    table.insert(1, "abc");
    table.insert(1, "def");
    table.insert(2, "ghi");

    REQUIRE(table.retreive(1) == "def");
    REQUIRE(table.retreive(3) == std::nullopt);
}

TEST_CASE("checking removals") {
    hash_table<int, std::string> table;

    table.insert(1, "abc");
    table.insert(2, "def");
    table.remove(1);

    REQUIRE(table.retreive(1) == std::nullopt);
    REQUIRE(table.retreive(2) == "def")
}