### Mini Tutorial for the Skip List class

    1. skip_list<T> -- creates a skip list with T type elements.

### **insert**:
```cpp
#include <skip_list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.    
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.
```

### **remove**:
```cpp
#include <skip_list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.

s.remove(13); // removes 13 from the list.
```

### **search**:
```cpp
#include <skip_list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.

// returns true if the key is in the list.
if(s.search(13)){
    std::cout << "element 13 found in the list" << '\n';
}
```

### **iterator**:
```cpp
#include <skip_list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.

for(auto it = s.begin(); it != s.end(); it++){
    // *(it) returns the value of each node(at the level 0)
    std::cout << *it << '\n';
}
```