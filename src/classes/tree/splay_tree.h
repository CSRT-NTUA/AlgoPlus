#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <memory>
#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <iostream>
#endif

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

public:
  /**
   * @brief Construct a new splay tree object
   *
   * @param v vector<T> initializer vector
   */
  explicit splay_tree(std::vector<T> v = {}) noexcept : root(nullptr) {
    if (!v.empty()) {
      for (T &x : v) {
        this->insert(x);
      }
    }
  }

  ~splay_tree() { root = nullptr; }

  /**
   * @brief insert function
   *
   * @param key the key to be inserted
   */
  void insert(T key) { root = __insert(root, key); }

  void remove(T key);

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

#endif