### Algoplus

AlgoPlus is a C++ library that includes ready to use complex Data Structures.

![Algoplus](https://github.com/CSRT-NTUA/AlgoPlus/blob/main/assets/logo.png)

Examples:
```cpp
doubly_linked_list<int> l1, l2;
  l1.push_back(1);
  l1.push_back(3);
  l1.push_back(4);
  for (doubly_list_iter<int> it = l1.begin(); it != l1.end(); it++) {
    std::cout << *(it) << '\n';
  }

  linked_list<int> l1, l2;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(-1);
  for (list_iter<int> it = l1.begin(); it != l1.end(); it++) {
    std::cout << *(it) << '\n';
  }
  if (l1.search(0)) {
    std::cout << "Yes" << '\n';
  }

  bst<char> b1;
  b1.insert('a');
  b1.insert('c');
  b1.insert('d');
  vector<vector<char>> v = b1.level_order();
```


### How to contribute  
1. Suggest new implementations on our already implemented data structures & algorithms, or, suggest new classes or algorithms(Note that the code **must** follow our code-style to be accepted).
2. Contribute to unit testing by writting unit tests for our classes and algorithms.
3. Contribute to the api code for other languages.
4. Promote the repository on your local workshop/seminar and get a shout-out.

### Classes
