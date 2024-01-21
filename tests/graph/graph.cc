#define CATCH_CONFIG_MAIN
#include "../../src/classes/graph/graph.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing clearing of a graph"){
  graph<int> g("directed", { {0, {1,2}}, {1, {3,4}}, {2, {4,5}}});
  g.clear();
  std::vector<int> v = g.topological_sort();
  std::vector<int> v2 = g.dfs(0);
  REQUIRE(v2.empty() == true);
  REQUIRE(v.empty() == true);
}

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

  graph<char> g2("undirected");
  g2.add_edge('a', 'g');
  g2.add_edge('b', 'o');
  g2.add_edge('o', 'a');
  g2.add_edge('w', 'e');
  REQUIRE(g2.connected_components() == 2);
}

TEST_CASE("testing cycle detection") {
  graph<int> g("undirected");
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 1);
  REQUIRE(g.cycle() == true);

  graph<int> g2("directed");
  g2.add_edge(1, 2);
  g2.add_edge(2, 3);
  g2.add_edge(3, 1);
  REQUIRE(g2.cycle() == true);

  graph<int> g3("directed");
  g3.add_edge(4, 5);
  g3.add_edge(5, 6);
  g3.add_edge(4, 6);
  REQUIRE(g3.cycle() == false);

  graph<char> g4("directed");
  g4.add_edge('a', 'c');
  g4.add_edge('c', 'a');
  REQUIRE(g4.cycle() == true);
}

TEST_CASE("testing topological sorting") {
  graph<int> g("directed");
  g.add_edge(0, 1);
  g.add_edge(1, 3);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  std::vector<int> v1 = {2, 0, 1, 3, 4};
  REQUIRE(g.topological_sort() == v1);
}

TEST_CASE("testing bipartite check"){
  graph<char> g("undirected");
  g.add_edge('a', 'b');
  g.add_edge('b', 'c');
  g.add_edge('c', 'd');
  g.add_edge('d', 'a');
  REQUIRE(g.bipartite() == true);
}

