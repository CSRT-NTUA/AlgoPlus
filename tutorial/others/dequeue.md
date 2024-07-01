### Mini Tutorial for the Stack class

    dequeue_list<T> -- creates a dequeue implemented with a list.

splay tree contains:
    - push_back
    - push_front
    - front
    - back
    - pop_front
    - pop_back
    - clear
    - size

### **push_back**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_back(10);
q.push_back(5);
q.push_back(4);
q.push_back(13);
// now the dequeue contains {10,5,4,13}
```

### **push_front**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

// now the dequeue contains {13,4,5,10}
```

### **front**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

// this should return 13
std::cout << q.front() << '\n';
```

### **back**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

// this should return 10
std::cout << q.back() << '\n';
```

### **pop_front**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

// pops the front element from the dequeue
q.pop_front();

// this should return 4
std::cout << q.front() << '\n';
```

### **pop_back**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

// pops the back element from the dequeue
q.pop_back();

// this should return 5
std::cout << q.back() << '\n';
```

### **iterator**:
```cpp
#include <dequeue_list.h>

dequeue_list<int> q;
q.push_front(10);
q.push_front(5);
q.push_front(4);
q.push_front(13);

for(auto it = q.begin(); it != q.end(); it++){
    // *(it) returns the value of the node
    std::cout << *(it) << ' ';
}
```