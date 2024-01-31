#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#ifdef __cplusplus
#include <vector>
#endif

class dsu {
private:
  std::vector<uint64_t> p;
  std::vector<uint64_t> depth;
  std::vector<uint64_t> ssize;
  std::vector<uint64_t> max_el;
  std::vector<uint64_t> min_el;

public:
  explicit dsu(uint64_t n) {
    p.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      p[i] = i;
    }
    depth.assign(n, 0);
    max_el.assign(n, 0);
    min_el.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      depth[i] = 0;
      max_el[i] = i;
      min_el[i] = i;
    }
    ssize.assign(n, 0);
    for (uint64_t i = 0; i < n; i++) {
      ssize[i] = 1;
    }
  }

  uint64_t find(uint64_t i) {
    if (p[i] == i) {
      return i;
    }
    return (p[i] = find(p[i]));
  }
  void join(uint64_t i, uint64_t j) {
    if (same(i, j)) {
      return;
    }

    uint64_t x = find(i);
    uint64_t y = find(j);

    if (depth[x] > depth[y]) {
      std::swap(x, y);
    }
    p[x] = y;

    if (depth[x] == depth[y]) {
      depth[y]++;
    }
    ssize[y] += ssize[x];
    max_el[y] = std::max(max_el[x], max_el[y]);
    min_el[y] = std::min(min_el[x], min_el[y]);
  }

  bool same(uint64_t i, uint64_t j) {
    if (find(i) == find(j)) {
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

  uint64_t size(uint64_t i) { return ssize[find(i)]; }

  uint64_t get_max(uint64_t i) { return max_el[find(i)]; }

  uint64_t get_min(uint64_t i) { return min_el[find(i)]; }
};

#endif