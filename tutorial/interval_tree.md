### Mini Tutorial for the Interval Tree class

    1. interval_tree<T> -- creates an interval tree with pairs of <T,T>

### **insert**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});
```

### **search**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

if(i.search({10,15})){
    std::cout << "interval {10,15} found in the tree" << '\n';
}
```


### **remove**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

//removes an interval from the tree
i.remove({0,1});
assert(i.search({0,1}) == false)
```

### **overlap**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

if(i.overlap({0,5}, {1,6})){
    std::cout << "Overlap between {0,5} and {1,6} exist!" << '\n';
}
```
### **inorder**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

// returns the elements of the tree in inorder fashion
std::vector<int> inorder = i.inorder();
```

### **preorder**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

// returns the elements of the tree in preorder fashion
std::vector<int> preorder = i.preorder();
```

### **postorder**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

// returns the elements of the tree in preorder fashion
std::vector<int> postorder = i.postorder();
```

### **visualize**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});
// returns a .dot file that automatically opens
// using graphviz plugins on vscode(or locally with 
// command lines).
i.visualize();
```

### **iterator**:
```cpp
#include <interval_tree.h>

interval_tree<int> i;
i.insert({20, 36});
i.insert({3, 41});
i.insert({29, 99});
i.insert({0, 1});
i.insert({10, 15});

for(auto it = i.begin(); it != i.end(); it++){
    // *(it) returns the pair of each node
    std::pair<int ,int> p = *(it);
    std::cout << p.first << " " << p.second << '\n';
}
```





