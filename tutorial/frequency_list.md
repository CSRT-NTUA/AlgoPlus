### Mini Tutorial for the frequency_list class

    1. frequency_list<T> flist; creates an empty frequency list with T type elements.
    2. frequency_list<T> flist({1, 2, 3, 4}); creates a frequency list and initializes it with the given values.

### **push_back**:
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_back(10);  // Inserts 10 to the list.
flist.push_back(5);   // Inserts 5 to the list.
flist.push_back(13);  // Inserts 13 to the list.
```

### **push_front**:
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_front(7);  // Inserts 7 to the front of the list.
flist.push_front(2);  // Inserts 2 to the front of the list.
```

### **search**:
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_back(10);  // Inserts 10 to the list.
flist.push_back(5);   // Inserts 5 to the list.
flist.push_back(13);  // Inserts 13 to the list.

// Returns true if the key is found in the list and increment the frequency.
if(flist.search(5)){
    std::cout << "Element 5 found in the list" << '\n';
}
```

### **get_frequency**:
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_back(10);  
flist.push_back(10);  // Frequency of 10 becomes 2

auto freq = flist.get_frequency(10); // Returns the frequency of 10
```

### **erase**:
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_back(10);
flist.push_back(5);
flist.push_back(13);

flist.erase(13);  // Removes 13 from the list.
```

### **empty**
```cpp
#include "frequency_list.h"

frequency_list<int> flist;

if (flist.empty()) {
    std::cout << "The list is empty." << '\n';
}
```

### **Iterator**
```cpp
#include "frequency_list.h"

frequency_list<int> flist;
flist.push_back(10);  
flist.push_back(5);
flist.push_back(13);

for(auto it = flist.begin(); it != flist.end(); it++){
    std::cout << *it << '\n';
}
```