### Mini Tutorial for the BST class

    bst<T> -- creates an avl tree.

avl tree contains:
    - insert
    - remove
    - clear
    - search
    - inorder
    - preorder
    - postorder
    - visualize
  
### **insert**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
//creates a tree with elements {4,5,10,13};
```

### **remove**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);
//removes the element 4 from the tree.
```

### **search**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);

//returns true if an element is in the tree.
if(b.search(4)){
    std::cout<< "element 4 found in the tree" << '\n';
}
```

### **inorder**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);

//returns the elements in inorder fashion.
std::vector<int> in = b.inorder();
```

### **preorder**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);

//returns the elements in preorder fashion.
std::vector<int> pre = b.preorder();
```

### **postorder**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);

//returns the elements in postorder fashion.
std::vector<int> in = a.postorder();
```

### **visualize**:
```cpp
#include <bst.h>

bst<int> b;
b.insert(10);
b.insert(5);
b.insert(4);
b.insert(13);
b.remove(4);

//returns a .dot file that can easily be previewed using
//vscode plugin for graphviz or local command line tools.
b.visualize();
```
