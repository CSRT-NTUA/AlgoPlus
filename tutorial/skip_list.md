### Mini Tutorial for the Skip List class

    1. skip_list<T> -- creates a skip list with T type elements.

### **insert**:
```cpp
#include <algoplus/list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.
```

### **remove**:
```cpp
#include <algoplus/list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.

s.remove(13); // removes 13 from the list.
```

### **search**:
```cpp
#include <algoplus/list.h>

skip_list<int> s(3, 0.5);
s.insert(10); // inserts 10 to the list.
s.insert(5); // inserts 5 to the list.
s.insert(13); // inserts 13 to the list.

// returns true if the key is in the list.
if(s.search(13)){
    std::cout << "element 13 found in the list" << '\n';
}

```