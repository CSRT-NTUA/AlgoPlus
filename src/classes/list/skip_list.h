#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#ifdef __cplusplus
#include <iostream>
#include <stdexcept>
#endif

/*
 *skip_list class.
 */

template <typename T> class skip_list {
public:
  /*
   *skip_list constructor.
   *@param __MAX_LEVEL: max height of the list.
   *@param __PROB: probability of increasing the height each time(by default it
   *should be 0.5).
   */
  explicit skip_list(int __MAX_LEVEL, float __PROB) : level(0) {
    try {
      if (__MAX_LEVEL < 5) {
        MAX_LEVEL = __MAX_LEVEL;
        root = std::make_shared<node>(0, __MAX_LEVEL);
      } else {
        throw std::invalid_argument("Max level value is too high");
      }
      if (__PROB > 0.0 && __PROB < 1.0) {
        PROB = __PROB;
      } else if (__PROB >= 1.0) {
        throw std::invalid_argument(
            "Probability value is greater or equal to 1");
      } else if (__PROB <= 0.0) {
        throw std::invalid_argument(
            "Probability value is smaller or equal to 0");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }

  ~skip_list() noexcept {}

  /*
   *insert function.
   *@param key: key to be inserted.
   */
  void insert(T key) {
    std::shared_ptr<node> head = root;
    std::vector<std::shared_ptr<node>> update(MAX_LEVEL + 1, nullptr);

    for (int i = level; i >= 0; i--) {
      while (head->next[i] != nullptr && head->next[i]->key < key) {
        head = head->next[i];
      }
      update[i] = head;
    }

    head = head->next[0];
    if (!head || head->key != key) {
      int lvl = rand_lvl();
      if (lvl > level) {
        for (int i = level + 1; i < lvl + 1; i++) {
          update[i] = root;
        }
        level = lvl;
      }

      std::shared_ptr<node> nn = std::make_shared<node>(key, lvl);
      for (int i = 0; i <= lvl; i++) {
        nn->next[i] = update[i]->next[i];
        update[i]->next[i] = nn;
      }
    }
  }

  /*
   *remove function.
   *@param key: key to be removed(if exist).
   */
  void remove(T key) {
    std::shared_ptr<node> x = root;
    std::vector<std::shared_ptr<node>> update(MAX_LEVEL + 1, nullptr);

    for (int64_t i = level; i >= 0; i--) {
      while (x->next[i] && x->next[i]->key < key) {
        x = x->next[i];
      }
      update[i] = x;
    }

    x = x->next[0];
    if (x && x->key == key) {
      for (int64_t i = 0; i <= level; i++) {
        if (update[i]->next[i] != x) {
          break;
        }
        update[i]->next[i] = x->next[i];
      }
      while (level > 0 && root->next[level] == nullptr) {
        level--;
      }
    }
  }

  /*
   *search function.
   *@param key: key to be searched.
   *Returns true if the key exists in the list.
   */
  bool search(T key) {
    std::shared_ptr<node> x = root;
    for (int64_t i = level; i >= 0; i--) {
      while (x->next[i] && x->next[i]->key < key) {
        x = x->next[i];
      }
    }
    x = x->next[0];
    if (x && x->key == key) {
      return true;
    }
    return false;
  }

  /*
   *operator << for skip_list<T> class.
   */
  friend std::ostream &operator<<(std::ostream &out, skip_list<T> &l) {
    std::shared_ptr<node> root = l.root;
    out << "{";
    for (int i = 0; i <= l.level; i++) {
      out << i << ": ";
      std::shared_ptr<node> curr = l.root->next[i];
      while (curr != nullptr) {
        out << curr->key << " ";
        curr = curr->next[i];
      }
      out << '\n';
    }
    out << "}" << '\n';
    return out;
  }

private:
  int MAX_LEVEL;
  float PROB;
  struct node {
    T key;
    std::vector<std::shared_ptr<node>> next;
    node(T key, int level, void *value = nullptr) : key(key) {
      for (int i = 0; i < level + 1; i++) {
        next.push_back(nullptr);
      }
    }
  };

  int rand_lvl() {
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < PROB && lvl < MAX_LEVEL) {
      lvl++;
      r = (float)rand() / RAND_MAX;
    }
    return lvl;
  }

  int level;
  std::shared_ptr<node> root;
};

#endif