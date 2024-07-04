#pragma once
#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
#include <functional>
#include <iostream>
#include <queue>
#endif

/**
 * @brief tree class
 *
 */
template <typename T> class tree {
private:
  struct node {
    T info;
    std::shared_ptr<node> right;
    std::shared_ptr<node> left;
    node(T info) : info(info), left(nullptr), right(nullptr) {}
  };

  int64_t __size;
  std::shared_ptr<node> root;

public:
  /**
   * @brief constructor for tree class
   * @param v: the input vector of pairs(string and T) to avoid doing multiple
   * insertions
   */
  explicit tree(std::vector<std::pair<std::string, T>> v = {}) noexcept
      : root(nullptr) {
    if (!v.empty()) {
      for (std::pair<std::string, T> &x : v) {
        this->insert(x.first, x.second);
      }
    }
  }

  /**
   * @brief insert function
   * @param direction: string, directions for the insertion of value info
   * @param info: the value of the new node
   */
  void insert(std::string direction, T info) {
    std::shared_ptr<node> nn = std::make_shared<node>(info);
    if (!root) {
      __size++;
      root = nn;
      return;
    }
    int64_t i = 0;
    std::shared_ptr<node> head = root;
    while (head && i < direction.size() - 1) {
      if (direction[i] == 'r') {
        head = head->right;
      } else {
        head = head->left;
      }
      i++;
    }
    if (head && direction[i] == 'r') {
      head->right = nn;
    } else if (head && direction[i] == 'l') {
      head->left = nn;
    }
    __size++;
  }

  /**
   * @brief search function
   * @param key: the key to be searched
   * @return true: if the key exist in the tree
   * @return false: otherwise
   */
  bool search(T key) {
    std::queue<std::shared_ptr<node>> q;
    q.push(root);
    while (!q.empty()) {
      int64_t size = q.size();
      for (int64_t i = 0; i < size; ++i) {
        std::shared_ptr<node> current = q.front();
        q.pop();
        if (current->info == key) {
          return true;
        }
        if (current->right) {
          q.push(current->right);
        }
        if (current->left) {
          q.push(current->left);
        }
      }
    }
    return false;
  }

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
   * @brief inorder traversal
   * @return vector<T>: the inorder traversal of the tree
   */
  std::vector<T> inorder() {
    std::vector<T> ino;
    __inorder(
        [&](std::shared_ptr<node> callbacked) {
          ino.push_back(callbacked->info);
        },
        root);
    return ino;
  }

  /**
   * @brief postorder function
   * @return vector<T>: the postorder traversal of the tree
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
   * @brief preorder function
   * @return vector<T>: the preorder traversal of the tree
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
   * @brief level order function
   * @return vector<vector<T>>: the level order traversal of the tree
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

private:
  void __inorder(std::function<void(std::shared_ptr<node>)> callback,
                 std::shared_ptr<node> root) {
    if (root) {
      __inorder(callback, root->left);
      callback(root);
      __inorder(callback, root->right);
    }
  }

  void __preorder(std::function<void(std::shared_ptr<node>)> callback,
                  std::shared_ptr<node> root) {
    if (root) {
      callback(root);
      __preorder(callback, root->left);
      __preorder(callback, root->righ);
    }
  }

  void __postorder(std::function<void(std::shared_ptr<node>)> callback,
                   std::shared_ptr<node> root) {
    if (root) {
      __postorder(callback, root->right);
      callback(root);
      __postorder(callback, root->left);
    }
  }
};

template <typename T> class tree<T>::Iterator {
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
