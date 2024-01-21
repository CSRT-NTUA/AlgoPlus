#ifdef __cplusplus
#include <iostream>
#endif

/*
 *Link for the list<T> class.
 */
template <typename T> class __link {
private:
  T pvalue;
  std::shared_ptr<__link> psucc;

public:
  /*
   *contructor for __link class
   *@param value: value assigned to the new __link type.
   */
  explicit __link(T value = 0) : pvalue(value), psucc(nullptr) {}

  /*
   *val function.
   *Returns the value of the __link type.
   */
  T val() { return pvalue; }

  /*
   *succ function.
   *Returns the successor pointer of the __link type.
   */
  std::shared_ptr<__link> &succ() { return psucc; }
};

/*
 *Link for the doubly_linked_list<T> class.
 */
template <typename T> class doubly_link {
private:
  T pvalue;
  std::shared_ptr<doubly_link> psucc;
  std::shared_ptr<doubly_link> pprev;

public:
  /*
   *contructor for doubly_link class
   *@param value: value assigned to the new doubly_link type.
   */
  explicit doubly_link(T value = 0)
      : pvalue(value), psucc(nullptr), pprev(nullptr) {}

  /*
   *val function.
   *Returns the value of the doubly_link type.
   */
  T val() { return pvalue; }

  /*
   *succ function.
   *Returns the successor pointer of the doubly_link type.
   */
  std::shared_ptr<doubly_link> &succ() { return psucc; }
  /*
   *succ function.
   *Returns the previous pointer of the doubly_link type.
   */
  std::shared_ptr<doubly_link> &prev() { return pprev; }
};