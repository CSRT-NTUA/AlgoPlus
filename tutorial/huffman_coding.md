### Mini tutorial for huffman coding class
    -- huffman h(vector<string> v, MAX_DEPTH) creates a huffman object with the input text v and MAX_DEPTH(default = 10)


### **create_tree**:

```cpp
#include <machine_learning/image/huffman_encoding.h>

int main(){
    std::vector<std::string> text = {"hello", "world", "it's", "algoplus"};

    huffman h(text);
    // creates the huffman tree using the helper function compute_weights() 
    h.create_tree();
}
```

### **decode**:

```cpp
#include <machine_learning/image/huffman_encoding.h>

int main(){
    ...
    // get the decoded results from the alphabet text
    std::unordered_map<std::string, std::string> decoded = h.decode();
}
```
