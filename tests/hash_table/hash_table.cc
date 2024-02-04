#define CATCH_CONFIG_MAIN
#include "../../src/classes/hash_table/hash_table.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions, overriding insertions and retrievals") {
    hash_table<std::string, int> table;

    table.insert("abc", 1);
    table.insert("abc", 2);
    table.insert("def", 3);

    REQUIRE(table.retreive("abc") == 3);
    REQUIRE(table.retreive("ghi") == std::nullopt);
}

TEST_CASE("checking removals") {
    hash_table<std::string, int> table;

    table.insert("abc", 1);
    table.insert("def", 2);
    table.remove("abc");

    REQUIRE(table.retreive("abc") == std::nullopt);
    REQUIRE(table.retreive("def") == 2)
}