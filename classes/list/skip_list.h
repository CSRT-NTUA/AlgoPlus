#include <stdexcept>
#ifdef __cplusplus
#include "../../plotting/iterator/list_iterator.h"
#include <iostream>
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

  int rand_lvl() {
    int __level = 0;
    while (static_cast<float>(std::rand()) / RAND_MAX < PROB &&
           __level < MAX_LEVEL) {
      __level++;
    }
    return __level;
  }

  void insert(T key, void *value) {
    std::shared_ptr < node >> next;
  } // to be continued

private:
  int MAX_LEVEL;
  float PROB;
  struct node {
    T key;
    void *value;
    std::vector<std::shared_ptr<node>> next;
    node(T key, int level, void *value = nullptr) : key(key), value(value) {
      for (int i = 0; i < level + 1; i++) {
        next.push_back(nullptr);
      }
    }
  };
  int level;
  std::shared_ptr<node> root;
};