## Algoplus{BETA Version}

AlgoPlus is a C++ library that includes ready-to-use complex **data structures** and **algorithms**.

![Algoplus](https://github.com/CSRT-NTUA/AlgoPlus/blob/main/assets/logo.png)

[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/CSRT-NTUA/AlgoPlus)
[![CodeQL CI](https://github.com/TheAlgorithms/C-Plus-Plus/actions/workflows/codeql.yml/badge.svg)](https://github.com/CSRT-NTUA/AlgoPlus/actions/workflows/codeql.yml)
[![codecov](https://codecov.io/gh/CSRT-NTUA/AlgoPlus/graph/badge.svg?token=3SBDRHUQR5)](https://codecov.io/gh/CSRT-NTUA/AlgoPlus)
![GitHub repo size](https://img.shields.io/github/repo-size/CSRT-NTUA/AlgoPlus)

### **See the full documentation [here](https://csrt-ntua.github.io/AlgoPlus/)**

### **[Join](https://discord.gg/M9nYv4MHz6) our Discord** 

### Example:

```cpp
#include <graph.h>
graph<std::string> g("undirected");
g.add_edge("hello", "world");
g.add_edge("world", "universe");
g.add_edge("hello", "universe");

if(g.connected()){
    std::cout << "graph is connected" << '\n';
}

#include <graph.h>
weighted_graph<int> g("undirected");
g.add_edge(1, 4, 2);
g.add_edge(4, 5, 6);
g.add_edge(5, 2, 9);
g.add_edge(2, 8, 10);

// returns the shortest path from 1 to 2.
std::cout << g.shortest_path(1, 2) << '\n';
g.visualize() // You can visualize almost any of our implemented data structures!
```
You can see more [examples](/examples) or follow the [Tutorials](/tutorial).

### Classes

**Graphs** 
- [X] [Di-Graph](https://en.wikipedia.org/wiki/Directed_graph)
- [X] [Graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics))

**Trees**
- [X] [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree)
- [X] [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- [X] [Splay Tree](https://en.wikipedia.org/wiki/Splay_tree)
- [X] [Trie](https://en.wikipedia.org/wiki/Trie)
- [X] [Interval Tree](https://en.wikipedia.org/wiki/Interval_tree) 
- [X] [Min/Max Heap](https://en.wikipedia.org/wiki/Min-max_heap)

**Lists**
- [X] [Single Linked List](https://en.wikipedia.org/wiki/Linked_list)
- [X] [Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [X] [Circular Linked List](https://www.geeksforgeeks.org/circular-linked-list)
- [X] [Skip List](https://en.wikipedia.org/wiki/Skip_list)

**Other** 
- [X] [Disjoint set](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [X] [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [X] [Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
- [X] [Hash Table](https://en.wikipedia.org/wiki/Hash_table)

**Machine Learning(NEW!)**
- [X] [Kmeans](https://en.wikipedia.org/wiki/K-means_clustering)
- [X] [DBSCAN](https://en.wikipedia.org/wiki/DBSCAN)
- [X] [Linear Regression](https://en.wikipedia.org/wiki/Linear_regression)
- [X] [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding)
- [X] [Polynomial Regression](https://en.wikipedia.org/wiki/Polynomial_regression)


### **How to run test cases**
We have unit tests for every function of our implemented algorithms & data structures.It is very important to make sure that your code works before making any pull requests!  

**Linux/MacOS**
```
mkdir build && cd build
cmake ..
make
cd tests
./runUnitTests
```
**Windows**
```
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
make
cd tests
./runUnitTests
```

### **Our contributors**
<a href="https://github.com/CSRT-NTUA/AlgoPlus/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=CSRT-NTUA/AlgoPlus" />
</a>
   
### How to contribute  
1. Povide **new implementations** on our already implemented data structures & algorithms.

3. Implement **new classes / algorithms**.


2. Contribute to **unit testing** by writting unit tests for our classes and algorithms.


3. Create and contribute to **APIs for other languages**.


4. **Promote** the repository on your local workshop/seminar and **get a shout-out**.

See more [here](/CONTRIBUTE.md).
