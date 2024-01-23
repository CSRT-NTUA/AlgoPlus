#ifndef BST_H
#define BST_H

#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <functional>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>
#endif

/*
 *Class for BST tree.
 */
template <typename T> class bst {
public:
  /*
   *Contructor for BST tree class.
   *@param __elements: you can directly pass a vector<T> so you don't have to do
   *insert multiple times.
   */
  explicit bst(std::vector<T> __elements = {}) noexcept : root(nullptr) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->insert(x);
      }
    }
  }
  ~bst() noexcept {}

  /*
   *insert function.
   *@param key: key to be inserted.
   */
  void insert(T key) { root = __insert(root, key); }

  /*
   *search function.
   *@param key: key to be searched.
   */
  bool search(T key) { return __search(root, key); }

  /*
   *remove function.
   *@param key: key to be removed.
   */
  void remove(T key) { root = __remove(root, key); }

  /*
   *inorder function.
   *Returns vector<T>, the elements inorder.
   */
  std::vector<T> inorder() {
    std::vector<T> path;
    __inorder([&](node *callbacked) { path.push_back(callbacked->info); },
              root);
    return path;
  }

  /*
   *preorder function.
   *Returns vector<T>, the elements preorder.
   */
  std::vector<T> preorder() {
    std::vector<T> path;
    __preorder([&](node *callbacked) { path.push_back(callbacked->info); },
               root);
    return path;
  }

  /*
   *postorder function.
   *Returns vector<T>, the elements postorder.
   */
  std::vector<T> postorder() {
    std::vector<T> path;
    __postorder([&](node *callbacked) { path.push_back(callbacked->info); },
                root);
    return path;
  }

  /*
   *visualize function
   *Returns .dot file that can be previewed using graphviz in vscode.
   */
  void visualize() {
    std::string __generated = generate_visualization();
    visualization::visualize(__generated);
  }

private:
  /*
   *Struct for the node type pointer.
   *@param info: the value of the node.
   *@param left: pointer to the left.
   *@param right: pointer to the right.
   */
  typedef struct node {
    T info;
    node *right;
    node *left;
  } node;
  node *root;

  node *new_node(T &key) {
    node *p = new node;
    p->info = key;
    p->right = p->left = nullptr;
    return p;
  }

  node *__insert(node *root, T &key) {
    if (!root) {
      return new_node(key);
    } else {
      if (root->info < key) {
        root->right = __insert(root->right, key);
      } else {
        root->left = __insert(root->left, key);
      }
    }
    return root;
  }

  bool __search(node *root, T &key) {
    while (root) {
      if (root->info < key) {
        root = root->right;
      } else if (root->info > key) {
        root = root->left;
      } else {
        return true;
      }
    }
    return false;
  }

  node *__remove(node *root, T &key) {
    if (!root) {
      return root;
    }

    if (root->info < key) {
      root->right = __remove(root->right, key);
    } else if (root->info > key) {
      root->left = __remove(root->left, key);
    } else {
      if (!root->left && !root->right) {
        free(root);
        root = nullptr;
      } else if (!root->left) {
        node *temp = root->right;
        free(root);
        return temp;
      } else if (!root->right) {
        node *temp = root->left;
        free(root);
        return temp;
      } else {
        node *temp = root->right;
        while (temp->left) {
          temp = temp->left;
        }
        root->info = temp->info;
        root->right = __remove(root->right, temp->info);
      }
    }
    return root;
  }

  void __inorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      __inorder(callback, root->left);
      callback(root);
      __inorder(callback, root->right);
    }
  }

  void __postorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      __inorder(callback, root->left);
      __inorder(callback, root->right);
      callback(root);
    }
  }

  void __preorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      callback(root);
      __inorder(callback, root->left);
      __inorder(callback, root->right);
    }
  }

  std::string generate_visualization() {
    std::string __generate = __inorder_gen(root);
    return __generate;
  }

  std::string __inorder_gen(node *root) {
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