### Mini tutorial for circular linked list class

    doubly_linked_list<T> -- creates a doubly linked list with elements of type T

### **push_back**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_back(1);
l.push_back(2);
l.push_back(3);
//creates a doubly linked list with elements {1,2,3}
```

### **push_front**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);
//creates a doubly linked list with elements {3,2,1}
```

### **erase**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);
l.erase(2);
assert(l.search(2) == false);
```

### **search**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);
if(l.search(3) == true){
    std::cout << "element 3 found in the list" << '\n';
}
```

### **reverse**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);
l.reverse();
//now the linked list became {1,2,3}
```

### **elements**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);

//returns the elements of the doubly linked list in a vector<T>
std::vector<int> els = l.elements();
```

### **iterators**:
```cpp
#include <doubly_linked_list.h>

doubly_linked_list<int> l;
l.push_front(1);
l.push_front(2);
l.push_front(3);
for(auto it = l.begin(); it != l.end(); it++){
    // *(it) gives the value of each node
    std::cout << *(it) <<  ' ';
}
```

