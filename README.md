## Algoplus

AlgoPlus is a C++ library that includes ready to use complex Data Structures.

![Algoplus](https://github.com/CSRT-NTUA/AlgoPlus/blob/main/assets/logo.png)

[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/CSRT-NTUA/AlgoPlus)
[![CodeQL CI](https://github.com/TheAlgorithms/C-Plus-Plus/actions/workflows/codeql.yml/badge.svg)](https://github.com/CSRT-NTUA/AlgoPlus/actions/workflows/codeql.yml)
[![Awesome CI](https://github.com/CSRT-NTUA/AlgoPlus/workflows/Awesome%20CI%20Workflow/badge.svg)](https://github.com/CSRT-NTUA/AlgoPlus/actions?query=workflow%3A%22Awesome+CI+Workflow%22)
[![codecov](https://codecov.io/gh/spirosmaggioros/AlgoPlus/graph/badge.svg?token=OQGIP2OTC7)](https://codecov.io/gh/spirosmaggioros/AlgoPlus)
### Example:

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
You can see more [examples](/examples) or follow the [Tutorials](/tutorial).


### Classes

**Graphs** 
- [X] [Di-Graph](https://en.wikipedia.org/wiki/Directed_graph)
- [X] [Graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics))

**Trees**
- [X] [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree)
- [X] [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- [X] [B-Tree](https://en.wikipedia.org/wiki/B-tree)
- [X] [RB Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
- [X] [Trie](https://en.wikipedia.org/wiki/Trie)
- [X] [Min/Max Heap](https://en.wikipedia.org/wiki/Min-max_heap)

**Lists**
- [X] [Single Linked List](https://en.wikipedia.org/wiki/Linked_list)
- [X] [Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [X] [Skip List](https://en.wikipedia.org/wiki/Skip_list)

**Other** 
- [X] [Disjoint set](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)

   
### How to contribute  
1. Povide **new implementations** on our already implemented data structures & algorithms.

3. Implement **new classes / algorithms**.


2. Contribute to **unit testing** by writting unit tests for our classes and algorithms.


3. Create and contribute to **APIs for other languages**.


4. **Promote** the repository on your local workshop/seminar and **get a shout-out**.

See more [here](/CONTRIBUTE.md).
