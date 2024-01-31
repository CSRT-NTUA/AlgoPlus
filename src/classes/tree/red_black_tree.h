#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class rb_tree {
private:
  struct node {
    T val;
    std::shared_ptr<node> right;
    std::shared_ptr<node> left;
    std::shared_ptr<node> parent;
    int color; // 0 for black 1 for red

    node(T key = 0, int __color)
        : val(key), right(nullptr), left(nullptr), parent(nullptr),
          color(__color) {}
  };

  std::shared_ptr<node> root;

public:
  rb_tree(std::vector<T> v = {}) {
    if (!v.empty()) {
      for (T &x : v) {
        this->insert(x);
      }
    }
  }

  ~rb_tree() {}

  void insert(T key);

  void remove(T key);

  bool search(T key);

  std::vector<T> inorder();

  std::vector<T> preorder();

  std::vector<T> postorder();

private:
  void __insert(std::shared_ptr<node> root, T key) {
    if (!root) {
      std::shared_ptr<node> nn = std::make_shared<node>(key, 0);
      root = nn;
      return;
    } else {
      if (root->parent && root->parent->color == 0) {
      }
    }
  }
};

#endif