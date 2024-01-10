#ifndef GRAPH_H
#include "../../src/classes/graph/graph.h"
#endif

int main() {
  weighted_graph<int> g("directed", {{{1, 3}, {2, 4}}, {{3, 4}, {4, 5}}});
  g.add_edge(1, 3, 4);
  g.add_edge(3, 4, 5);
  g.add_edge(0, 1, 6);
  std::cout << g.shortest_path(0, 10) << '\n';

  graph<int> g2("directed", {{1, 3}, {3, 4}, {4, 5}});
  std::vector<int> v = g2.bfs(0);
  for (auto &x : v) {
    std::cout << x << " ";
  }
  std::cout << '\n';
}
