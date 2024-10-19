### Mini tutorial for segment tree class(as well as the iterative one)

-- seg_tree<T> or segment_tree creates a segment tree(of nodes with type T or not :) )
Both of the classes can be used the same way, so this tutorial will only cover the iterative one as it's easier to understsand

### *seg_tree default constructor*:
```cpp
// The default constructor takes a vector of type T as an argument
// and builds the tree

vector<int> v = {0, 5, 12, 4, 2, 1};
seg_tree<int> tree(v);
```

### *sum query*:
```cpp
// Sum queries can be computed on O(logn) time
// Sum queries returns the sum from index a to index b
cout << tree.sum(0, 2) << '\n';
```

### *update query*:
```cpp
// Update query updates the value on index i to x
tree.update(0, 1);
// after this, the array will be [1, 5, 12, 4, 2, 1]
```
