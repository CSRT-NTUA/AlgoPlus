#define CATCH_CONFIG_MAIN
#include "../../src/classes/graph/graph.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing dfs") {
  graph<int> g("directed");
  g.add_edge(1, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 5);

  std::vector<int> v = {1, 3, 4, 5};
  std::vector<int> dfs = g.dfs(1);
  REQUIRE(v == dfs);
}

TEST_CASE("testing bfs") {
  graph<int> g("directed");
  g.add_edge(1, 4);
  g.add_edge(4, 5);
  g.add_edge(6, 7);
  g.add_edge(7, 8);
  std::vector<int> v1 = {1, 4, 5}, v2 = {6, 7, 8};
  std::vector<int> dfs1 = g.dfs(1), dfs2 = g.dfs(6);
  REQUIRE(v1 == dfs1);
  REQUIRE(v2 == dfs2);
}

TEST_CASE("testing connecting components") {
  graph<int> g("undirected");
  g.add_edge(1, 2);
  g.add_edge(2, 4);
  g.add_edge(5, 6);
  g.add_edge(7, 8);
  REQUIRE(g.connected_components() == 3);
}
