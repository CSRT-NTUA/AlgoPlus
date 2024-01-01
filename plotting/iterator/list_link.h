#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class link {
private:
  T pvalue;
  std::shared_ptr<link> psucc;

public:
  explicit link(T value = 0) : pvalue(value), psucc(nullptr) {}
  T val() { return pvalue; }

  std::shared_ptr<link> &succ() { return psucc; }
};

template <typename T> class doubly_link {
private:
  T pvalue;
  std::shared_ptr<doubly_link> psucc;
  std::shared_ptr<doubly_link> pprev;

public:
  explicit doubly_link(T value = 0)
      : pvalue(value), psucc(nullptr), pprev(nullptr) {}

  T val() { return pvalue; }

  std::shared_ptr<doubly_link> &succ() { return psucc; }
  std::shared_ptr<doubly_link> &prev() { return pprev; }
};