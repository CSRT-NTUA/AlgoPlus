#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#ifdef __cplusplus
#include <vector>
#endif

class dsu {
private:
  std::vector<uint64_t> p;       ///< keeps track of the parent of ith element
  std::vector<uint64_t> depth;   ///< tracks the depth(rank) of i in the tree
  std::vector<uint64_t> setSize; ///< size of each chunk(set)
  std::vector<uint64_t>
      maxElement; ///< maximum of each set to which i belongs to
  std::vector<uint64_t>
      minElement; ///< minimum of each set to which i belongs to
public:
  explicit dsu(uint64_t n) {
    p.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      p[i] = i;
    }
    depth.assign(n, 0);
    maxElement.assign(n, 0);
    minElement.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      depth[i] = 0;
      maxElement[i] = i;
      minElement[i] = i;
    }
    setSize.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      setSize[i] = 1;
    }
  }

  uint64_t findSet(uint64_t i) {
    if (p[i] == i) {
      return i;
    }
    return (p[i] = findSet(p[i]));
  }
  void UnionSet(uint64_t i, uint64_t j) {
    if (isSame(i, j)) {
      return;
    }

    uint64_t x = findSet(i);
    uint64_t y = findSet(j);

    if (depth[x] > depth[y]) {
      std::swap(x, y);
    }
    p[x] = y;

    if (depth[x] == depth[y]) {
      depth[y]++;
    }
    setSize[y] += setSize[x];
    maxElement[y] = std::max(maxElement[x], maxElement[y]);
    minElement[y] = std::min(minElement[x], minElement[y]);
  }

  bool isSame(uint64_t i, uint64_t j) {
    if (findSet(i) == findSet(j)) {
      return true;
    }
    return false;
  }

  std::vector<uint64_t> get(uint64_t i) {
    std::vector<uint64_t> ans;
    ans.push_back(get_min(i));
    ans.push_back(get_max(i));
    ans.push_back(size(i));
    return ans;
  }

  uint64_t size(uint64_t i) { return setSize[findSet(i)]; }

  uint64_t get_max(uint64_t i) { return maxElement[findSet(i)]; }

  uint64_t get_min(uint64_t i) { return minElement[findSet(i)]; }
};

#endif