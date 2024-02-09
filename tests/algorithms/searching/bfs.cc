#include "../../../src/algorithms/searching/bfs.h"
#include "../../catch2/catch.hpp"

TEST_CASE("testing breadth first search")
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

    int key = 7;
    int start = 0;
    int result = bfs(graph, start, key);
    REQUIRE(result == key);
}