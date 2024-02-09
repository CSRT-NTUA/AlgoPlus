#include "../../../src/algorithms/searching/dfs.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing depth first search")
{
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {0, 4, 5},
        {0, 6, 7},
        {0, 8, 9},
        {1},
        {1},
        {2},
        {2},
        {3},
        {3}};

    std::unordered_set<int> visited;
    int key = 7;
    int start = 0;
    int result = dfs(graph, start, visited, key);
    REQUIRE(result == key);
}