### Mini Tutorial for the Splay Tree class

    splay_tree<T> -- creates a splay tree.

splay tree contains:
    - insert
    - remove
    - search
    - clear
    - size
    - inorder
    - preorder
    - postorder
    - visualize
  
### **insert**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
//creates a tree with elements {4,5,10,13};
```

### **remove**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);
//removes the element 4 from the tree.
```

### **search**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);

//returns true if an element is in the tree.
if(s.search(4)){
    std::cout<< "element 4 found in the tree" << '\n';
}
```

### **inorder**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);

//returns the elements in inorder fashion.
std::vector<int> in = s.inorder();
```

### **preorder**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);

//returns the elements in preorder fashion.
std::vector<int> pre = s.preorder();
```

### **postorder**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);

//returns the elements in postorder fashion.
std::vector<int> in = a.postorder();
```

### **visualize**:
```cpp
#include <splay_tree.h>

splay_tree<int> s;
s.insert(10);
s.insert(5);
s.insert(4);
s.insert(13);
s.remove(4);

//returns a .dot file that can easily be previewed using
//vscode plugin for graphviz or local command line tools.
s.visualize();
```
