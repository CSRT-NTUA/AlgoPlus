#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

#include <memory>
#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#endif

/**
 *@brief interval tree class
 */
template <typename T> class interval_tree {
public:
  /**
   * @brief Construct a new interval tree object
   *
   * @param v : vector<pair<T,T>> initializer
   */
  interval_tree(std::vector<std::pair<T, T>> v = {}) {
    if (!v.empty()) {
      for (auto &x : v) {
        this->insert({x.first, x.second});
      }
    }
  }

  ~interval_tree() { root = nullptr; }

  /**
   * @brief clear function
   */
  void clear() {
    root = nullptr;
    __size = 0;
  }

  /**
   *@brief insert function.
   *@param p: interval to be inserted.
   */
  void insert(std::pair<T, T> p) {
    interval i = interval(p);
    root = __insert(root, i);
    __size++;
  }

  /**
   *@brief search function.
   *@returns true if an interval exist in the tree.
   */
  bool search(std::pair<T, T> p) {
    if (!root) {
      return false;
    }
    interval i = interval(p);
    if (this->overlap({root->i->low, root->i->high}, p)) {
      return true;
    }
    return __search(root, i);
  }

  /**
   *@brief remove function.
   *@param p: interval to be removed.
   */
  void remove(std::pair<T, T> p) {
    interval i = interval(p);
    root = __remove(root, i);
    __size--;
  }

  /**
   *@brief overlap function.
   *@param p1: first interval.
   *@param p2: second interval.
   *@returns true if p1 overlaps p2.
   */
  bool overlap(std::pair<T, T> p1, std::pair<T, T> p2) {
    interval i1 = interval(p1), i2 = interval(p2);
    return i1.high >= i2.low && i1.low <= i2.high;
  }

  class Iterator;

  /**
   * @brief pointer that points to begin
   *
   * @return Iterator
   */
  Iterator begin() {
    std::vector<std::pair<T, T>> ino = this->inorder();
    return Iterator(0, ino);
  }

  /**
   * @brief pointer that points to end
   *
   * @return Iterator
   */
  Iterator end() {
    std::vector<std::pair<T, T>> ino = this->inorder();
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
   *@returns vector<pair<T,T>>, the elements inorder.
   */
  std::vector<std::pair<T, T>> inorder() {
    std::vector<std::pair<T, T>> path;
    __inorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back({callbacked->i->low, callbacked->i->high});
        },
        root);
    return path;
  }

  /**
   *@brief preorder function.
   *@returns vector<pair<T,T>>, the elements preorder.
   */
  std::vector<std::pair<T, T>> preorder() {
    std::vector<std::pair<T, T>> path;
    __preorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back({callbacked->i->low, callbacked->i->high});
        },
        root);
    return path;
  }

  /**
   *@brief postorder function.
   *@returns vector<pair<T, T>>, the elements postorder.
   */
  std::vector<std::pair<T, T>> postorder() {
    std::vector<std::pair<T, T>> path;
    __postorder(
        [&](std::shared_ptr<node> callbacked) {
          path.push_back({callbacked->i->low, callbacked->i->high});
        },
        root);
    return path;
  }

  void visualize() {
    std::string __generated = generate_visualization();
    visualization::visualize(__generated);
  }

  /**
   *@brief << operator for interval_tree class.
   */
  friend std::ostream &operator<<(std::ostream &out, interval_tree<T> &t) {
    if (!t.root) {
      out << "";
      return out;
    }
    out << '"';
    std::vector<std::pair<T, T>> __inorder = t.inorder();
    for (auto &x : __inorder) {
      out << '"' << x.first << ' ' << x.second << '"' << " ";
    }
    out << '"';
    return out;
  }

private:
  /**
   * @brief struct for the intervals
   * @param low: the min of the pair
   * @param high: the high of the pair
   */
  struct interval {
    T low;
    T high;
    interval(std::pair<T, T> p)
        : low(std::min(p.first, p.second)), high(std::max(p.first, p.second)) {}
  };

  /**
   * @brief struct for the node
   * @param i: the interval
   * @param max: max of the interval
   * @param right: pointer to the right
   * @param left: pointer to the left
   *
   */
  struct node {
    interval *i;
    int max;
    std::shared_ptr<node> right;
    std::shared_ptr<node> left;
    node(interval n)
        : i(new interval(n)), max(n.high), right(nullptr), left(nullptr) {}
  };

  std::shared_ptr<node> root;
  size_t __size;

  std::shared_ptr<node> new_node(interval i) {
    std::shared_ptr<node> p = std::make_shared<node>(i);
    return p;
  }

  /**
   *@brief helper function for insertion
   */
  std::shared_ptr<node> __insert(std::shared_ptr<node> root, interval i) {
    if (!root) {
      return new_node(i);
    }
    T l = root->i->low;
    if (i.low < l) {
      root->left = __insert(root->left, i);
    } else {
      root->right = __insert(root->right, i);
    }
    if (root->max < i.high) {
      root->max = i.high;
    }
    return root;
  }

  /**
   *@brief helper function for search
   */
  bool __search(std::shared_ptr<node> root, interval i) {
    if (!root) {
      return false;
    }
    if (root->left && root->left->max >= i.low) {
      return __search(root->left, i);
    }
    return __search(root->right, i);
  }

  /**
   *@brief helper function for remove.
   */
  std::shared_ptr<node> __remove(std::shared_ptr<node> root, interval i) {
    if (!root) {
      return nullptr;
    }
    std::shared_ptr<node> p = root;
    while (p) {
      if (p->i->low > i.low) {
        p = p->left;
      } else if (p->i->low < i.low) {
        p = p->right;
      } else {
        if (!p->right && !p->left) {
          return nullptr;
        } else if (p->right && !p->left) {
          std::shared_ptr<node> temp = root->right;
          return temp;
        } else if (p->left && !p->right) {
          std::shared_ptr<node> temp = p->left;
          return temp;
        } else {
          std::shared_ptr<node> temp = root;
          while (temp && temp->left) {
            temp = temp->left;
          }
          p->i = temp->i;
          p->max = temp->max;
          p->right = __remove(p->right, *temp->i);
        }
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
        __s += '"';
        __s += root->i->low;
        __s += ',';
        __s += root->i->high;
        __s += '"';
        __s += "->";
        __s += '"';
        __s += root->left->i->low;
        __s += ',';
        __s += root->left->i->high;
        __s += '"';
        __s += "\n";
        __s += __inorder_gen(root->left);
      }
      if (root->right) {
        __s += '"';
        __s += root->i->low;
        __s += ',';
        __s += root->i->high;
        __s += '"';
        __s += "->";
        __s += '"';
        __s += root->right->i->low;
        __s += ',';
        __s += root->right->i->high;
        __s += '"';
        __s += "\n";
        __s += __inorder_gen(root->right);
      }
    } else {
      if (root->left) {
        __s += '"';
        __s += std::to_string(root->i->low);
        __s += ',';
        __s += std::to_string(root->i->high);
        __s += '"';
        __s += "->";
        __s += '"';
        __s += std::to_string(root->left->i->low);
        __s += ',';
        __s += std::to_string(root->left->i->high);
        __s += '"';
        __s += "\n";
        __s += __inorder_gen(root->left);
      }
      if (root->right) {
        __s += '"';
        __s += std::to_string(root->i->low);
        __s += ',';
        __s += std::to_string(root->i->high);
        __s += '"';
        __s += "->";
        __s += '"';
        __s += std::to_string(root->right->i->low);
        __s += ',';
        __s += std::to_string(root->right->i->high);
        __s += '"';
        __s += "\n";
        __s += __inorder_gen(root->right);
      }
    }
    return __s;
  }
};

/**
 * @brief Iterator class
 */
template <typename T> class interval_tree<T>::Iterator {
private:
  std::vector<std::pair<T, T>> elements;
  int64_t index;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param els vector<pair<T,T>> - the elements in inorder fashion
   */
  explicit Iterator(const int64_t &index,
                    std::vector<std::pair<T, T>> &els) noexcept
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
   * @return std::pair<T,T> the value of the node
   */
  std::pair<T, T> operator*() {
    return {elements[index].first, elements[index].second};
  }
};

#endif
