#ifdef __cplusplus
#include "../../plotting/iterator/list_iterator.h"
#include <iostream>
#include <stdexcept>
#endif

template <typename T> class skip_list {
public:
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

  friend std::ostream &operator<<(std::ostream &out, skip_list<T> &l) {
    out << "{";
    for (int i = 0; i < l.level; i++) {
      out << i << ": ";
      while (l.root->next[i] != nullptr) {
        out << l.root->next[i]->key << ' ';
        l.root->next[i] = l.root->next[i]->next[i];
      }
      if (i != l.level - 1) {
        out << '\n';
      }
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
    int __level = 0;
    while (static_cast<float>(std::rand()) / RAND_MAX < PROB &&
           __level < MAX_LEVEL) {
      std::cout << 1 << '\n';
      __level++;
    }
    return __level;
  }

  int level;
  std::shared_ptr<node> root;
};