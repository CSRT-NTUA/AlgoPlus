### Mini tutorial for the 234 tree class
    --- ttf_tree<T> creates a 234 tree.

### **insert**:
```cpp
#include <234_tree.h>

ttf_tree<int> t;
t.insert(10);
t.insert(5);
t.insert(4);
t.insert(13);
// creates a tree with elements {4,5,10,13[
```

### **search**:
```cpp
#include <234_tree.h>

ttf_tree<int> t;
t.insert(10);
t.insert(5);
t.insert(4);
t.insert(13);

//returns true if the element exists in the tree
assert(t.search(13) == true);
assert(t.search(50) == false);
```

### **level order**:
```cpp
#include <234_tree.h>

ttf_tree<int> t;
t.insert(10);
t.insert(5);
t.insert(4);
t.insert(13);
// return the elements in level order fashion
std::vector<std::vector<std::vector<int> > > level_ordered = t.level_order();
```