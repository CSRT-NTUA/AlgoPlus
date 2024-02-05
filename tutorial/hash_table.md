### Mini Tutorial for the hash_table class

    hash_table -- creates a hash table(dictionary).

### **Create an instance of the hash_table:**:
```cpp
#include <hash_table.h>

hash_table<std::string, int> ht;
// creates a hash table with keys of type std::string and values of type int
```


### **insert**:
```cpp
#include <hash_table.h>

hash_table<std::string, int> ht;
ht.insert("apple", 1);
ht.insert("banana", 2);
ht.insert("carrot", 3);
// inserts key-value pairs {"apple", 1}, {"banana", 2}, {"carrot", 3} into the hash table

```

### **retrieve**:
```cpp
#include <hash_table.h>

hash_table<std::string, int> ht;
ht.insert("apple", 1);
ht.insert("banana", 2);
ht.insert("carrot", 3);

// retrieves the value associated with the given key.
auto opt_value = ht.retrieve("banana");
if(opt_value) {
    std::cout << *opt_value << '\n';  // will print 2
} else {
    std::cout << "Element not found" << '\n';
}
```

### **remove**:
```cpp
#include <hash_table.h>

hash_table<std::string, int> ht;
ht.insert("apple", 1);
ht.insert("banana", 2);
ht.insert("carrot", 3);

// removes the key-value pair associated with the given key from the hash_table.
ht.remove("carrot");
assert(!ht.retrieve("carrot"));
```

### **iterator**:
```cpp
#include <hash_table.h>

hash_table<std::string, int> ht;
ht.insert("apple", 1);
ht.insert("banana", 2);
ht.insert("carrot", 3);

for(auto it = ht.begin(); it != ht.end(); it++){
    // *(it) returns the list of pairs that exist in each index
    std::list<std::pair<std::string, int>> l = *(it);
}
```
