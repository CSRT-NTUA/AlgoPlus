#include "../../src/classes/graph/graph.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing clearing of a graph") {
  weighted_graph<int> g("directed");
  g.add_edge(1, 2, 4);
  g.add_edge(2, 3, 4);
  g.add_edge(4, 5, 5);
  g.clear();
  std::vector<int> v = g.topological_sort();
  std::vector<int> v2 = g.dfs(1);
  REQUIRE(v.empty() == true);
  REQUIRE(v2.empty() == true);
}

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

TEST_CASE("testing cycle detection") {
  weighted_graph<int> g("undirected");
  g.add_edge(0, 1, 0);
  g.add_edge(2, 3, 4);
  g.add_edge(1, 2, 10);
  g.add_edge(3, 0, 9);
  REQUIRE(g.cycle() == true);

  weighted_graph<int> g2("directed");
  g2.add_edge(0, 1, 0);
  g2.add_edge(2, 3, 0);
  g2.add_edge(1, 2, 0);
  g2.add_edge(0, 3, 0);
  REQUIRE(g2.cycle() == false);
}

TEST_CASE("testing shortest path in DAG") {
  weighted_graph<int> g2("directed");
  g2.add_edge(0, 1, 10);
  g2.add_edge(2, 3, 8);
  g2.add_edge(1, 2, 6);
  g2.add_edge(0, 3, 4);
  REQUIRE(g2.shortest_path(0, 3) == 4);

  weighted_graph<int> g3("directed");
  g3.add_edge(0, 1, 0);
  g3.add_edge(1, 2, 2);
  g3.add_edge(2, 6, 3);
  g3.add_edge(1, 6, 1);
  g3.add_edge(3, 2, 4);
  REQUIRE(g3.shortest_path(0, 6) == 1);
}

TEST_CASE("testing mst with prim's algo") {
  weighted_graph<int> g("directed");
  g.add_edge(1, 2, 2);
  g.add_edge(0, 1, 0);
  g.add_edge(2, 6, 3);
  g.add_edge(1, 6, 1);
  g.add_edge(3, 2, 4);
  REQUIRE(g.prim(0) == 3);
}

TEST_CASE("testing bipartite graph") {
  weighted_graph<char> g("undirected");
  g.add_edge('a', 'b', 1);
  g.add_edge('b', 'c', 2);
  g.add_edge('c', 'd', 3);
  g.add_edge('d', 'a', 4);
  REQUIRE(g.bipartite() == true);
}

TEST_CASE("testing size") {
  weighted_graph<int> g("undirected");
  g.add_edge(1, 2, 4);
  g.add_edge(4, 5, 6);
  g.add_edge(2, 4, 6);
  g.add_edge(2, 7, 6);
  g.add_edge(2, 44, 6);
  g.add_edge(2, 1, 6);
  g.add_edge(2, 100, 6);
  g.add_edge(100, 4, 6);
  g.add_edge(200, 4, 6);
  REQUIRE(g.size() == 8);
}

TEST_CASE("testing if an edge exist") {
  weighted_graph<char> g("directed");
  g.add_edge('a', 'c', 5);
  g.add_edge('a', 'd', 5);
  g.add_edge('e', 'f', 5);
  g.add_edge('f', 'a', 5);
  REQUIRE(g.has_edge('a', 'd') == true);
  REQUIRE(g.has_edge('a', 'f') == false);

  weighted_graph<int> g2("undirected");
  g2.add_edge(1, 3, 10);
  g2.add_edge(5, 10, 30);
  g2.add_edge(3, 5, 40);
  g2.add_edge(1, 10000, 100);
  REQUIRE(g2.has_edge(1, 10000) == true);
  REQUIRE(g2.has_edge(10, 5) == true);
  REQUIRE(g2.has_edge(1, 5) == false);
}

TEST_CASE("testing bridge detection") {
  weighted_graph<int> g("undirected");
  g.add_edge(1, 0, 5);
  g.add_edge(0, 2, 10);
  g.add_edge(1, 2, 3);
  g.add_edge(0, 3, 9);
  g.add_edge(3, 4, 11);

  std::vector<std::vector<int>> bridges = {{4, 3}, {3, 0}};
  REQUIRE(g.bridge(0) == bridges);
}

TEST_CASE("testing connectivity") {
  weighted_graph<int> g("undirected");
  g.add_edge(1, 0, 10);
  g.add_edge(0, 2, 15);
  g.add_edge(1, 2, 100);
  g.add_edge(0, 3, 2);
  g.add_edge(3, 4, 4);
  g.add_edge(4, 0, 10);
  REQUIRE(g.connected() == true);

  weighted_graph<int> g2("undirected");
  g2.add_edge(0, 1, 100);
  g2.add_edge(5, 6, 9999);
  REQUIRE(g2.connected() == false);
}

TEST_CASE("testing eulerian check") {
  weighted_graph<int> g("undirected");
  g.add_edge(1, 3, 5);
  g.add_edge(1, 0, 10);
  g.add_edge(1, 2, 4);
  g.add_edge(2, 0, 3);
  g.add_edge(0, 3, 14);
  g.add_edge(3, 4, 13);

  REQUIRE(g.eulerian() == 0);

  weighted_graph<int> g2("undirected");
  g2.add_edge(1, 2, 11);
  g2.add_edge(2, 0, 10);
  g2.add_edge(1, 0, 8);
  g2.add_edge(0, 3, 4);
  g2.add_edge(3, 4, 3);
  REQUIRE(g2.eulerian() == 1);

  weighted_graph<int> g3("undirected");
  g3.add_edge(1, 0, 10);
  g3.add_edge(1, 2, 12);
  g3.add_edge(2, 0, 13);
  g3.add_edge(0, 3, 15);
  g3.add_edge(0, 4, 13);
  g3.add_edge(3, 4, 8);
  REQUIRE(g3.eulerian() == 2);
}

TEST_CASE("testing bellman ford algorithm") {
  weighted_graph<int> g2("undirected");
  g2.add_edge(1, 2, 11);
  g2.add_edge(2, 0, 10);
  g2.add_edge(1, 0, 8);
  g2.add_edge(0, 3, 4);
  g2.add_edge(3, 4, 3);
  unordered_map<int, double> test = g2.bellman_ford(1);
  unordered_map<int, double> check;
  check[1] = 0.0;
  check[2] = 11.0;
  check[0] = 8;
  check[3] = 12;
  check[4] = 15;

  REQUIRE(check == test);

  weighted_graph<int> g("directed");
  g.add_edge(1, 2, -6);
  g.add_edge(2, 3, 5);
  g.add_edge(3, 1, -2);
  unordered_map<int, double> test2 = g.bellman_ford(1);
  unordered_map<int, double> check2;
  check2[2] = -std::numeric_limits<double>::infinity();
  check2[3] = -std::numeric_limits<double>::infinity();
  check2[1] = -std::numeric_limits<double>::infinity();
  REQUIRE(check2 == test2);
}