#define CATCH_CONFIG_MAIN
#include "../../src/classes/graph/graph.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing shortest path") {
  weighted_graph<int> g("undirected");
  g.add_edge(1, 2, 5);
  g.add_edge(3, 4, 1);
  g.add_edge(2, 5, 10);
  g.add_edge(5, 8, 10);
  g.add_edge(4, 8, 5);
  g.add_edge(2, 3, 1);

  REQUIRE(g.shortest_path(1, 8) == 12);
}

TEST_CASE("testing conected components") {
  weighted_graph<int> g("undirected"), g2("undirected");
  g.add_edge(1, 2, 6);
  g.add_edge(2, 3, 6);
  g.add_edge(6, 7, 1);
  g.add_edge(7, 8, 2);
  REQUIRE(g.connected_components() == 2);

  g2.add_edge(1, 2, 6);
  g2.add_edge(2, 3, 5);
  g2.add_edge(3, 5, 7);
  REQUIRE(g2.connected_components() == 1);
}