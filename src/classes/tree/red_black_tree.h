#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class rb_tree {
private:
  struct node {
    T val;
    int64_t height;
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
  int64_t getBalance(std::shared_ptr<node> root) {
    return height(root->left) - height(root->right);
  }

  std::shared_ptr<node> rightRotate(std::shared_ptr<node> root) {
    std::shared_ptr<node> t = root->left;
    std::shared_ptr<node> u = t->right;
    t->right = root;
    root->left = u;
    return t;
  }

  std::shared_ptr<node> leftRotate(std::shared_ptr<node> root) {
    std::shared_ptr<node> t = root->right;
    std::shared_ptr<node> u = t->left;
    t->left = root;
    root->right = u;
    return t;
  }

  void __insert(std::shared_ptr<node> root, T key) {
    if (!root) {
      std::shared_ptr<node> nn = std::make_shared<node>(key, 0);
      root = nn;
      return;
    } else {
      if (root->parent && root->parent->color == 0) {
        std::shared_ptr<node> nn = std::make_shared<node>(key, 1);
      }
    }
  }
};

#endif