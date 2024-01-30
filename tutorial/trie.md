### Mini Tutorial for the Trie class

    trie -- creates an trie tree(or prefix tree).

### **insert**:
```cpp
#include <algoplus/trie.h>

trie t;
t.insert("hello");
t.insert("world");
t.insert("universe");
// creates a tree with elements {"hello", "world", "universe"}
```
### **search**:
```cpp
#include <algoplus/trie.h>

trie t;
t.insert("hello");
t.insert("world");
t.insert("universe");

//returns true if the word exists in the tree.
if(t.search("world")){
    std::cout << "world exists in the tree" << '\n';
}

```

### **remove**:
```cpp
#include <algoplus/trie.h>

trie t;
t.insert("hello");
t.insert("world");
t.insert("universe");

//removes an element from the tree.
t.remove("universe");
assert(t.search("universe") == false);
```
