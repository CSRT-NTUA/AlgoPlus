#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class __link {
private:
  T pvalue;
  std::shared_ptr<__link> psucc;

public:
  explicit __link(T value = 0) : pvalue(value), psucc(nullptr) {}
  T val() { return pvalue; }

  std::shared_ptr<__link> &succ() { return psucc; }
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