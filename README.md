### Algoplus

AlgoPlus is a C++ library that includes ready to use complex Data Structures.

![Algoplus](https://github.com/CSRT-NTUA/AlgoPlus/blob/main/assets/logo.png)

[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/CSRT-NTUA/AlgoPlus)
[![CodeQL CI](https://github.com/TheAlgorithms/C-Plus-Plus/actions/workflows/codeql.yml/badge.svg)](https://github.com/CSRT-NTUA/AlgoPlus/actions/workflows/codeql.yml)
[![Awesome CI](https://github.com/CSRT-NTUA/AlgoPlus/workflows/Awesome%20CI%20Workflow/badge.svg)](https://github.com/CSRT-NTUA/AlgoPlus/actions?query=workflow%3A%22Awesome+CI+Workflow%22)

Examples:
```cpp
#include <algoplus/graph.h>
graph<std::string> g("undirected");
g.add_edge("hello", "world");
g.add_edge("world", "universe");
g.add_edge("hello", "universe");

if(g.connected()){
    std::cout << "graph is connected" << '\n';
}

#include <algoplus/graph.h>
weighted_graph<int> g("undirected");
g.add_edge(1, 4, 2);
g.add_edge(4, 5, 6);
g.add_edge(5, 2, 9);
g.add_edge(2, 8, 10);

// returns the shortest path from 1 to 2.
std::cout << g.shortest_path(1, 2) << '\n';
```


### How to contribute  
1. Suggest new implementations on our already implemented data structures & algorithms, or, suggest new classes or algorithms(Note that the code **must** follow our code-style to be accepted).
2. Contribute to unit testing by writting unit tests for our classes and algorithms.
3. Contribute to the api code for other languages.
4. Promote the repository on your local workshop/seminar and get a shout-out.

### Classes
  * Graph
  * Multigraph
  * AVL Tree
  * Binary Search Tree
  * B-Tree
  * RB Tree
  * Trie
  * Single Linked List
  * Doubly Linked List
  * Skip List
  * Disjoint set
  * Min/Max Heap

   

