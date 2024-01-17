#ifdef __cplusplus
#include <iostream>
#include <vector>
#endif

template <typename T> class avl_iter {
public:
  avl_iter() noexcept {
    __elements = _get_inorder(root);
    index = 0;
  }
  avl_iter(const node *p) noexcept : root(p) {}
  ~avl_iter();

  avl_iter &operator++() {
    if (index >= 0 && index < __elements.size()) {
      index++;
    }
    return *this;
  }

  avl_iter operator++(int) {
    avl_iter it = *this;
    ++*this;
    return it;
  }

  bool operator!=(const avl_iter &it) { return root != it.root; }
  T operator*() { return __elements[index]; }

private:
  typedef struct node {
    T info;
    int64_t height;
    struct node *left;
    struct node *right;
  } node;
  node *root;
  std::vector<T> __elements;
  int64_t index;

  std::vector<T> __get_inorder(node *root) {
    std::vector<T> p;
    __inorder(root, p);
    return p;
  }

  void __inorder(node *root, std::vector<T> &p) {
    if (root) {
      __inorder(root->left, p);
      p.push_back(root->info);
      __inorder(root->right, p);
    }
  }
};