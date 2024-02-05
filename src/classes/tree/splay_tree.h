#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#endif

/**
 * @brief splay tree class
 */
template <typename T> class splay_tree {
private:
  /**
   * @brief stuct for the node
   * @param info: the value of the node
   * @param right: pointer to the right
   * @param left: pointer to the left
   */
  struct node {
    T info;
    std::shared_ptr<node> right;
    std::shared_ptr<node> left;
    node(T key = 0) : info(key), right(nullptr), left(nullptr) {}
  };
  std::shared_ptr<node> root;
  size_t __size;

public:
  /**
   * @brief Construct a new splay tree object
   *
   * @param v vector<T> initializer vector
   */
  explicit splay_tree(std::vector<T> v = {}) noexcept
      : root(nullptr), __size(0) {
    if (!v.empty()) {
      for (T &x : v) {
        this->insert(x);
      }
    }
  }

  ~splay_tree() { root = nullptr; }

  /**
   * @brief clear function
   */
  void clear() {
    root = nullptr;
    __size = 0;
  }

  /**
   * @brief insert function
   *
   * @param key the key to be inserted
   */
  void insert(T key) {
    root = __insert(root, key);
    __size++;
  }

  /**
   * @brief remove function
   *
   * @param key the key to be removed
   */
  void remove(T key) {
    root = __remove(root, key);
    __size--;
  }

  /**
   * @brief search function
   *
   * @param key
   * @return true if key exists in the tree
   * @return false otherwise
   */
  bool search(T key) {
    std::shared_ptr<node> ans = splay(root, key);
    return (ans && ans->info == key);
  }

  /**
   * @brief size function
   *
   * @return size_t the size of the tree
   */
  size_t size() { return __size; }

  class Iterator;

  Iterator begin() {
    std::vector<T> ino = this->inorder();
    return Iterator(0, ino);
  }

  Iterator end() {
    std::vector<T> ino = this->inorder();
    return Iterator(ino.size(), ino);
  }

  /**
   *@brief inorder function.
   *@returns vector<T>, the elements inorder.
   */
  std::vector<T> inorder() {
    std::vector<T> path;
    __inorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back(callbacked->info);
        },
        root);
    return path;
  }

  /**
   *@brief preorder function.
   *@returns vector<T>, the elements preorder.
   */
  std::vector<T> preorder() {
    std::vector<T> path;
    __preorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back(callbacked->info);
        },
        root);
    return path;
  }

  /**
   *@brief postorder function.
   *@returns vector<T>, the elements postorder.
   */
  std::vector<T> postorder() {
    std::vector<T> path;
    __postorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back(callbacked->info);
        },
        root);
    return path;
  }

  /**
   *@brief visualize function
   *@returns .dot file that can be previewed using graphviz in vscode.
   */
  void visualize() {
    std::string __generated = generate_visualization();
    visualization::visualize(__generated);
  }

private:
  std::shared_ptr<node> rrotate(std::shared_ptr<node> _node) {
    std::shared_ptr<node> y = _node->left;
    _node->left = y->right;
    y->right = _node;
    return y;
  }

  std::shared_ptr<node> lrotate(std::shared_ptr<node> _node) {
    std::shared_ptr<node> y = _node->right;
    _node->right = y->left;
    y->left = _node;
    return y;
  }

  std::shared_ptr<node> splay(std::shared_ptr<node> _node, T key) {
    if (!_node || _node->info == key) {
      return _node;
    }
    if (_node->info > key) {
      if (_node->left == NULL)
        return _node;
      if (_node->left->info > key) {
        _node->left->left = splay(_node->left->left, key);
        _node = rrotate(_node);
      } else if (_node->left->info < key) {
        _node->left->right = splay(_node->left->right, key);
        if (_node->left->right != NULL)
          _node->left = lrotate(_node->left);
      }
      return (_node->left == NULL) ? _node : rrotate(_node);
    } else {
      if (_node->right == NULL)
        return _node;
      if (_node->right->info > key) {
        _node->right->left = splay(_node->right->left, key);
        if (_node->right->left != NULL)
          _node->right = rrotate(_node->right);
      } else if (_node->right->info < key) {
        _node->right->right = splay(_node->right->right, key);
        _node = lrotate(_node);
      }
      return (_node->right == NULL) ? _node : lrotate(_node);
    }
  }

  std::shared_ptr<node> __insert(std::shared_ptr<node> root, T key) {
    if (!root) {
      std::shared_ptr<node> nn = std::make_shared<node>(key);
      return nn;
    }
    root = splay(root, key);
    if (root->info == key) {
      return root;
    }

    std::shared_ptr<node> nn = std::make_shared<node>(key);
    if (root->info > key) {
      nn->right = root;
      nn->left = root->left;
      root->left = nullptr;
    } else {
      nn->left = root;
      nn->right = root->right;
      root->right = nullptr;
    }
    return nn;
  }

  std::shared_ptr<node> __remove(std::shared_ptr<node> root, T key) {
    if (!root) {
      return nullptr;
    }
    root = splay(root, key);
    if (key != root->info) {
      return root;
    }

    std::shared_ptr<node> temp;
    temp = root;
    if (!root->left) {
      root = root->right;
    } else {
      root = splay(root->left, key);
      root->right = temp->right;
    }
    return root;
  }

  void __inorder(std::function<void(std::shared_ptr<node>)> callback,
                 std::shared_ptr<node> root) {
    if (root) {
      __inorder(callback, root->left);
      callback(root);
      __inorder(callback, root->right);
    }
  }

  void __postorder(std::function<void(std::shared_ptr<node>)> callback,
                   std::shared_ptr<node> root) {
    if (root) {
      __postorder(callback, root->left);
      __postorder(callback, root->right);
      callback(root);
    }
  }

  void __preorder(std::function<void(std::shared_ptr<node>)> callback,
                  std::shared_ptr<node> root) {
    if (root) {
      callback(root);
      __preorder(callback, root->left);
      __preorder(callback, root->right);
    }
  }

  std::string generate_visualization() {
    std::string __generate = __inorder_gen(root);
    return __generate;
  }

  std::string __inorder_gen(std::shared_ptr<node> root) {
    std::string __s;
    if (std::is_same_v<T, char> || std::is_same_v<T, std::string>) {
      if (root->left) {
        __s += root->info;
        __s += "->";
        __s += root->left->info;
        __s += "\n";
        __s += __inorder_gen(root->left);
      }
      if (root->right) {
        __s += root->info;
        __s += "->";
        __s += root->right->info;
        __s += "\n";
        __s += __inorder_gen(root->right);
      }
    } else {
      if (root->left) {
        __s += std::to_string(root->info) + "->" +
               std::to_string(root->left->info) + "\n" +
               __inorder_gen(root->left);
      }
      if (root->right) {
        __s += std::to_string(root->info) + "->" +
               std::to_string(root->right->info) + "\n" +
               __inorder_gen(root->right);
      }
    }
    return __s;
  }
};

/**
 * @brief Iterator class
 */
template <typename T> class splay_tree<T>::Iterator {
private:
  std::vector<T> elements;
  int64_t index;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param els vector<T> - the elements in inorder fashion
   */
  explicit Iterator(const int64_t &index, std::vector<T> &els) noexcept
      : index(index), elements(els) {}

  /**
   * @brief = operator for Iterator type
   *
   * @param index the current index
   * @return Iterator&
   */
  Iterator &operator=(int64_t index) {
    this->index = index;
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator++() {
    if (this->index < elements.size()) {
      this->index++;
    }
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator
   */
  Iterator operator++(int) {
    Iterator it = *this;
    ++*(this);
    return it;
  }

  /**
   * @brief operator != for type Iterator
   *
   * @param it const Iterator
   * @return true if index == it.index
   * @return false otherwise
   */
  bool operator!=(const Iterator &it) { return index != it.index; }

  /**
   * @brief operator * for type Iterator
   *
   * @return T the value of the node
   */
  T operator*() { return elements[index]; }
};

#endif