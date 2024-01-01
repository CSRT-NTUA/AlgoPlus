#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class link {
private:
  T pvalue;
  std::shared_ptr<link> psucc;

public:
  int val() { return pvalue; }

  std::shared_ptr<link> &succ() { return psucc; }

  explicit link(T value = 0) : pvalue(value), psucc(nullptr) {}
};