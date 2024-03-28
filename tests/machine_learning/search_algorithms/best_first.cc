#include "../../../third_party/catch.hpp"
#include "../../../src/machine_learning/search_algorithms/best_first/best_first.h"
#include <string>

TEST_CASE("testing search function"){
  best_first<char> h;
  h.insert_node('s', INT_MAX);
  h.insert_node('A', 10.4);
  h.insert_node('B', 6.7);
  h.insert_node('C', 3.2);
  h.insert_node('D', 5.6);
  h.insert_node('E', 5.3);
  h.insert_node('F', 4.33);
  h.insert_node('G', 0.0);
  h.add_edge('s', 'D');
  h.add_edge('A', 'B');
  h.add_edge('A', 'D');
  h.add_edge('D', 'E');
  h.add_edge('E', 'F');
  h.add_edge('F', 'G');
  REQUIRE(h.search('s', 'G') == true);

  best_first<char> h2;
  h2.insert_node('s', INT_MAX);
  h2.insert_node('A', 10.4);
  h2.insert_node('B', 6.7);
  h2.insert_node('C', 3.2);
  h2.insert_node('D', 5.6);
  h2.insert_node('E', 5.9);
  h2.insert_node('F', 4.33);
  h2.insert_node('G', 0.0);
  h2.add_edge('s', 'D');
  h2.add_edge('A', 'B');
  h2.add_edge('A', 'D');
  h2.add_edge('D', 'E');
  h2.add_edge('E', 'F');
  h2.add_edge('F', 'G');

  REQUIRE(h2.search('s', 'G') == false);
}


