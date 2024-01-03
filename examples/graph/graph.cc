#ifndef GRAPH_H
#include "../../classes/graph/graph.h"
#endif

int main() {
  weighted_graph<int> g("directed");
  g.add_edge(1, 3, 4);
  g.add_edge(3, 4, 5);
  g.add_edge(0, 1, 6);
  std::cout << g.shortest_path(1, 4) << '\n';
}
