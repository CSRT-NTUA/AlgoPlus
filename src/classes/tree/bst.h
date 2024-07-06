#pragma once
#ifndef BST_H
#define BST_H

#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>
#endif

/**
 *@brief Class for BST tree.
 */
template <typename T> class bst {
public:
  /**
   *@brief Contructor for BST tree class.
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

  /**
   * @brief Copy constructor for bst class
   * @param b the tree we want to copy
   */
  explicit bst(const bst &b) {
    root = b.root;
    __size = b.__size;
  }

  /**
   * @brief operator = for bst class
   * @param b the tree we want to copy
   * @return bst&
   */
  bst &operator=(const bst &b) {
    root = b.root;
    __size = b.__size;
    return *this;
  }

  ~bst() noexcept { root = nullptr; }

  /**
   * @brief clear function
   */
  void clear() {
    root = nullptr;
    __size = 0;
  }

  /**
   *@brief insert function.
   *@param key: key to be inserted.
   */
  void insert(T key) {
    root = __insert(root, key);
    __size++;
  }

  /**
   *@brief search function.
   *@param key: key to be searched.
   *@returns true if the key exists in the tree.
   */
  bool search(T key) { return __search(root, key); }

  /**
   *@brief remove function.
   *@param key: key to be removed.
   */
  void remove(T key) {
    root = __remove(root, key);
    __size--;
  }

  class Iterator;

  /**
   * @brief pointer that points to begin
   *
   * @return Iterator
   */
  Iterator begin() {
    std::vector<T> ino = this->inorder();
    return Iterator(0, ino);
  }

  /**
   * @brief pointer that points to end
   *
   * @return Iterator
   */
  Iterator end() {
    std::vector<T> ino = this->inorder();
    return Iterator(ino.size(), ino);
  }

  /**
   * @brief size function
   *
   * @return size_t the size of the tree
   */
  size_t size() { return __size; }

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
   * @brief level order function
   * @return vector<vector<T>>, the level order traversal of the tree
   */
  std::vector<std::vector<T>> level_order() {
    std::vector<std::vector<T>> path;
    std::queue<std::shared_ptr<node>> q;
    q.push(root);
    while (!q.empty()) {
      size_t size = q.size();
      std::vector<T> level;
      for (size_t i = 0; i < size; i++) {
        std::shared_ptr<node> current = q.front();
        q.pop();
        level.push_back(current->info);
        if (current->left) {
          q.push(current->left);
        }
        if (current->right) {
          q.push(current->right);
        }
      }
      path.push_back(level);
    }
    return path;
  }

  /**
   *@brief visualize function
   *@returns .dot file that can be previewed using graphviz in vscode.
   */
  void visualize() {
    std::string __generated = generate_visualization();
    tree_visualization::visualize(__generated);
  }

  
  /**
   * @brief operator << for bst class
   */
  friend ostream & operator << (ostream &out, bst<T> &t){
    std::vector<std::vector<T> > order = t.inorder();
    for(int i = 0; i<order.size(); i++){
      if(i != order.size() - 1){
        out << order[i] << ", ";
      }
      else{
        out << order[i] << '\n';
      }
    }
    return out;
  }

private:
  /**
   *@brief Struct for the node type pointer.
   *@param info: the value of the node.
   *@param left: pointer to the left.
   *@param right: pointer to the right.
   */
  typedef struct node {
    T info;
    std::shared_ptr<node> right;
    std::shared_ptr<node> left;
    node(T key) : info(key), right(nullptr), left(nullptr) {}
  } node;

  std::shared_ptr<node> root;
  size_t __size;

  std::shared_ptr<node> new_node(T &key) {
    std::shared_ptr<node> p = std::make_shared<node>(key);
    return p;
  }

  std::shared_ptr<node> __insert(std::shared_ptr<node> root, T &key) {
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

  bool __search(std::shared_ptr<node> root, T &key) {
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

  std::shared_ptr<node> __remove(std::shared_ptr<node> root, T &key) {
    if (!root) {
      return root;
    }

    if (root->info < key) {
      root->right = __remove(root->right, key);
    } else if (root->info > key) {
      root->left = __remove(root->left, key);
    } else {
      if (!root->left && !root->right) {
        root = nullptr;
      } else if (!root->left) {
        std::shared_ptr<node> temp = root->right;
        return temp;
      } else if (!root->right) {
        std::shared_ptr<node> temp = root->left;
        return temp;
      } else {
        std::shared_ptr<node> temp = root->right;
        while (temp->left) {
          temp = temp->left;
        }
        root->info = temp->info;
        root->right = __remove(root->right, temp->info);
      }
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
template <typename T> class bst<T>::Iterator {
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
   * @brief operator -- for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator--() {
    if (this->index > 0) {
      this->index--;
    }
    return *(this);
  }

  /**
   * @brief operator -- for type Iterator
   *
   * @return Iterator
   */
  Iterator operator--(int) {
    Iterator it = *this;
    --*(this);
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
