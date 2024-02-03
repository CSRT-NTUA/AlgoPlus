### Mini Tutorial for the Stack class

    stack_list<T> -- creates a stack implemented with a list.

splay tree contains:
    - push
    - top
    - pop
    - clear
    - size

### **push**:
```cpp
#include <stack_list.h>

stack_list<int> s;
s.push(10);
s.push(5);
s.push(4);
s.push(13);
// now the stack contains {10,5,4,13}
```

### **top**:
```cpp
#include <stack_list.h>

stack_list<int> s;
s.push(10);
s.push(5);
s.push(4);
s.push(13);

// this should return 13
std::cout << s.top() << '\n';
```

### **pop**:
```cpp
#include <stack_list.h>

stack_list<int> s;
s.push(10);
s.push(5);
s.push(4);
s.push(13);

// removes the top, in this case, 13
s.pop();

//this should return 4
std::cout << s.top() << '\n';
```