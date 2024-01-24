#define CATCH_CONFIG_MAIN
#include "../../src/classes/graph/graph.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing clearing of a graph") {
  graph<int> g("directed", {{0, {1, 2}}, {1, {3, 4}}, {2, {4, 5}}});
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

TEST_CASE("testing bipartite check") {
  graph<char> g("undirected");
  g.add_edge('a', 'b');
  g.add_edge('b', 'c');
  g.add_edge('c', 'd');
  g.add_edge('d', 'a');
  REQUIRE(g.bipartite() == true);
}

TEST_CASE("testing size") {
  graph<std::string> g("directed");
  g.add_edge("hello", "there");
  g.add_edge("i'm", "batman");
  g.add_edge("batman", "hero");
  g.add_edge("hero", "hello");
  REQUIRE(g.size() == 5);
}

TEST_CASE("testing if an edge exists") {
  graph<int> g("directed");
  g.add_edge(1, 5);
  g.add_edge(5, 10);
  g.add_edge(3, 5);
  g.add_edge(5, 1);
  REQUIRE(g.has_edge(1, 5) == true);
  REQUIRE(g.has_edge(1, 10) == false);
  REQUIRE(g.has_edge(5, 1) == true);

  graph<int> g2("undirected");
  g2.add_edge(1, 3);
  g2.add_edge(5, 10);
  g2.add_edge(3, 5);
  g2.add_edge(1, 10000);
  REQUIRE(g2.has_edge(1, 10000) == true);
  REQUIRE(g2.has_edge(10, 5) == true);
  REQUIRE(g2.has_edge(1, 5) == false);
}

TEST_CASE("testing bridge detection") {
  graph<int> g("undirected");
  g.add_edge(1, 0);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 4);

  std::vector<std::vector<int>> bridges = {{4, 3}, {3, 0}};
  REQUIRE(g.bridge(0) == bridges);
}

TEST_CASE("testing connectivity") {
  graph<int> g("undirected");
  g.add_edge(1, 0);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 0);
  REQUIRE(g.connected() == true);

  graph<int> g2("undirected");
  g2.add_edge(0, 1);
  g2.add_edge(5, 6);
  REQUIRE(g2.connected() == false);
}

TEST_CASE("testing eulerian check") {
  graph<int> g("undirected");
  g.add_edge(1, 3);
  g.add_edge(1, 0);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(0, 3);
  g.add_edge(3, 4);

  REQUIRE(g.eulerian() == 0);

  graph<int> g2("undirected");
  g2.add_edge(1, 2);
  g2.add_edge(2, 0);
  g2.add_edge(1, 0);
  g2.add_edge(0, 3);
  g2.add_edge(3, 4);
  REQUIRE(g2.eulerian() == 1);

  graph<int> g3("undirected");
  g3.add_edge(1, 0);
  g3.add_edge(1, 2);
  g3.add_edge(2, 0);
  g3.add_edge(0, 3);
  g3.add_edge(0, 4);
  g3.add_edge(3, 4);
  REQUIRE(g3.eulerian() == 2);
}