### Mini Tutorial for the AVL tree class

    avl_tree<T> -- creates an avl tree.

avl tree contains:
    - insert
    - remove
    - search
    - inorder
    - preorder
    - postorder
    - visualize
  
### **insert**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
//creates a tree with elements {4,5,10,13};
```

### **remove**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);
//removes the element 4 from the tree.
```

### **search**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

//returns true if an element is in the tree.
if(a.search(4)){
    std::cout<< "element 4 found in the tree" << '\n';
}
```

### **inorder**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

//returns the elements in inorder fashion.
std::vector<int> in = a.inorder();
```

### **preorder**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

//returns the elements in preorder fashion.
std::vector<int> pre = a.preorder();
```

### **postorder**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

//returns the elements in postorder fashion.
std::vector<int> in = a.postorder();
```

### **visualize**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

//returns a .dot file that can easily be previewed using
//vscode plugin for graphviz or local command line tools.
a.visualize();
```

### **iterators**:
```cpp
#include <avl.h>

avl_tree<int> a;
a.insert(10);
a.insert(5);
a.insert(4);
a.insert(13);
a.remove(4);

for(auto it = a.begin(); it != a.end(); it++){
    // *(it) returns the value of the node
    //note that begin starts from the leftmost value
    std::cout << *(it) << ' ';
}
```