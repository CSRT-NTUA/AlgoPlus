### Mini tutorial for fenwick tree class

-- fenwick_tree<T> creates a fenwick tree with nodes of type T

### *default constructor*:
```cpp
vector<int> v = {1, 2, 3, 4, 5};
fenwick_tree<int> f(v); // this creates the fenwick tree
                        // with the passed vector v
```

### *sum query*:
```cpp
...
cout << f.sum(2) << '\n'; // this should return 6
cout << f.sum(0, 2) << '\n'; // this should return 6 as well
```

### *update query*:
```cpp
...
f.update(0, -5); // updates the value of index 0 to -4(1 + -5)
cout << f.sum(2) << '\n'; // this should return 1 now
cout << f.sum(0, 2) << '\n'; // this should return 1 as well
```
