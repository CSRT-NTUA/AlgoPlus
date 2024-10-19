### Mini tutorial for Red Black Tree class

  -- red_black_tree<T> creates a red black tree with nodes of type T

### *insert*:
```cpp
red_black_tree<int> r;
r.insert(10); // inserts 10 to the tree
r.insert(20); // inserts 20 to the tree
```

### *search*:
```cpp
...
if(r.search(10)) {
  cout << "We found 10!" << '\n';
}
else {
  cout << "10 is not found!" << '\n';
}
```

### *remove*:
```cpp
r.remove(10);
assert(r.search(10) == false);
```

### *size*:
```cpp
r.insert(10);
r.insert(30);
assert(r.size() == 3);
```

### *clear*:
```cpp
r.clear();
assert(r.size() == 0);
```

### *inorder*:
```cpp
r.insert(10);
r.insert(-10);
r.insert(20);
r.insert(30);
r.insert(25);
r.insert(12);

vector<int> ino = r.inorder(); // returns the inorder traversal of the tree
vector<int> check = {-10, 10, 12, 20, 25, 30};
asert(ino == check);
```

### *preorder*:
```cpp
...
vector<int> pre = r.preorder(); // returns the preorder traversal of the tree
```

### *postorder*:
```cpp
...
vector<int> post = r.postorder(); // returns the postorder traversal of the tree
```

### *Custom cout operator*:
```cpp
...
cout << r << '\n'; // for the impatient ones, we have a custom operator,
                   // as we do for almost all of our classes
```

### *iterators*:
```cpp
// You can use this class as a set-like structure
auto it = r.begin();
cout << *(it) << '\n';
it++;
...
```
