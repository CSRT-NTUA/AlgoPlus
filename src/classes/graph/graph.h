#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#endif

template <typename T> class graph {
public:
  graph(std::string __type, std::vector<std::vector<T>> __adj = {}) {
    try {
      if (__type == "directed" || __type == "undirected") {
        this->__type = __type;
      } else {
        throw std::invalid_argument("Can't recognize the type of graph");
      }
      if (!__adj.empty()) {
        for (size_t i = 0; i < __adj.size(); i++) {
          for (T &x : __adj[i]) {
            this->add_edge(i, x);
          }
        }
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }
  ~graph() {}

  void add_edge(T u, T v) {
    if (__type == "undirected") {
      adj[u].push_back(v);
      adj[v].push_back(u);
    } else {
      adj[u].push_back(v);
    }
    __elements.insert(u);
    __elements.insert(v);
  }

  size_t size();

  std::vector<T> dfs(T start);

  std::vector<T> bfs(T start);

  int64_t connected_components();

  bool cycle();

  std::vector<T> topological_sort();

  bool bipartite();

  friend std::ostream & operator <<(std::ostream &out, graph<T> &g){
    out << '{';

    std::vector<T> elements = g.topological_sort();
    for(T &x : elements){
      out << x << ' ';
    }
    out << '}' << '\n';
    return out;
  }

private:
  std::unordered_map<T, std::vector<T>> adj;
  std::unordered_set<T> __elements;
  std::string __type;
};

template<typename T> size_t graph<T>::size(){return __elements.size();}

template <typename T> std::vector<T> graph<T>::dfs(T start) {
  std::stack<T> s;
  std::vector<T> path;
  std::unordered_map<T, bool> visited;
  s.push(start);
  visited[start] = true;
  while (!s.empty()) {
    T current = s.top();
    path.push_back(current);
    s.pop();
    for (T &x : adj[current]) {
      if (visited.find(x) == visited.end()) {
        s.push(x);
        visited[x] = true;
      }
    }
  }
  return path;
}

template <typename T> std::vector<T> graph<T>::bfs(T start) {
  std::queue<T> q;
  std::vector<T> path;
  std::unordered_map<T, bool> visited;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int64_t size = q.size();
    for (int64_t i = 0; i < size; i++) {
      T current = q.front();
      path.push_back(current);
      q.pop();
      for (T &x : adj[current]) {
        if (visited.find(x) == visited.end()) {
          q.push(x);
          visited[x] = true;
        }
      }
    }
  }
  return path;
}

template <typename T> int64_t graph<T>::connected_components() {
  auto explore = [&](std::unordered_map<T, bool> &visited, T element) -> void {
    std::queue<T> q;
    q.push(element);
    visited[element] = true;
    while (!q.empty()) {
      T current = q.front();
      q.pop();
      for (T &x : adj[current]) {
        if (visited.find(x) == visited.end()) {
          q.push(x);
          visited[x] = true;
        }
      }
    }
  };
  size_t n = __elements.size();
  int64_t cc = 0;
  std::unordered_map<T, bool> visited;
  for (T x : __elements) {
    if (visited.find(x) == visited.end()) {
      explore(visited, x);
      cc++;
    }
  }
  return cc;
}

template <typename T> bool graph<T>::cycle() {
  std::unordered_map<T, int> indeg;
  std::queue<T> q;
  size_t visited = 0;

  for (T x : __elements) {
    for (T &y : adj[x]) {
      indeg[y]++;
    }
  }

  for (T x : __elements) {
    if (indeg[x] == 0) {
      q.push(x);
    }
  }

  while (!q.empty()) {
    T current = q.front();
    q.pop();
    visited++;
    for (T &x : adj[current]) {
      if (--indeg[x] == 0) {
        q.push(x);
      }
    }
  }
  return visited == 0;
}

template <typename T> std::vector<T> graph<T>::topological_sort() {
  std::vector<T> top_sort;
  std::unordered_map<T, bool> visited;
  std::unordered_map<T, int64_t> indeg;
  for (T x : __elements) {
    for (T &y : adj[x]) {
      indeg[y]++;
    }
  }

  std::queue<T> q;
  for (T x : __elements) {
    if (indeg[x] == 0) {
      q.push(x);
      visited[x] = true;
    }
  }

  while (!q.empty()) {
    T current = q.front();
    q.pop();
    top_sort.push_back(current);
    for (T &x : adj[current]) {
      if (visited.find(x) == visited.end()) {
        if (--indeg[x] == 0) {
          q.push(x);
          visited[x] = true;
        }
      }
    }
  }

  return top_sort;
}

template <typename T> bool graph<T>::bipartite(){
  std::unordered_map<T, int> color;
  std::queue<std::pair<T, int> > q;

  for(T x : __elements){
    if(color.find(x) == color.end()){
      q.push({x, 0});
      color[x] = 0;
      while(!q.empty()){
        std::pair<T, int> current = q.front();
        q.pop();
        T v = current.first;
        int col = current.second;
        for(T & x : adj[v]){
          if(color.find(x) != color.end() && color[x] == col){
            return false;
          }
          if(color.find(x) == color.end()){
            color[x] = (col) ? 0 : 1;
            q.push({x, color[x]});
          }
        }
      }
    }
  }
  return true;
}


template <typename T> class weighted_graph {
public:
  weighted_graph(std::string __type,
                 std::vector<std::vector<std::pair<T, int64_t>>> __adj = {{}}) {
    try {
      if (__type == "directed" || __type == "undirected") {
        this->__type = __type;
      } else {
        throw std::invalid_argument("Can't recognize the type of graph");
      }
      if (!__adj.empty()) {
        for (size_t i = 0; i < __adj.size(); i++) {
          for (std::pair<T, int64_t> &x : __adj[i]) {
            this->add_edge(i, x.first, x.second);
          }
        }
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }
  ~weighted_graph() { adj.clear(); }

  void add_edge(T u, T v, int64_t w) {
    if (__type == "undirected") {
      adj[u].push_back(std::make_pair(v, w));
      adj[v].push_back(std::make_pair(u, w));
    } else if (__type == "directed") {
      adj[u].push_back(std::make_pair(v, w));
    }
    __elements.insert(u);
    __elements.insert(v);
  }

  size_t size();

  std::vector<T> dfs(T start);

  std::vector<T> bfs(T start);

  int64_t shortest_path(T start, T end);

  int64_t connected_components();

  bool cycle();

  std::vector<T> topological_sort();

  int64_t prim(T start);

  bool bipartite();

  friend std::ostream &operator <<(std::ostream &out, weighted_graph<T> &g){
    out << '{';
    std::vector<T> elements = g.topological_sort();
    for(T &x : elements){
      out << x << ' ';
    }
    out << '}' << '\n';
    return out;
  }

private:
  std::unordered_map<T, std::vector<std::pair<T, int64_t>>> adj;
  std::string __type;
  std::unordered_set<T> __elements;
};

template <typename T> size_t weighted_graph<T>::size(){return __elements.size();}

template <typename T> int64_t weighted_graph<T>::shortest_path(T start, T end) {
  if (__elements.find(start) == __elements.end()) {
    std::cout << "Element: " << start << " is not found in the Graph" << '\n';
    return -1;
  }
  if (__elements.find(end) == __elements.end()) {
    std::cout << "Element: " << end << " is not found in the Graph" << '\n';
    return -1;
  }

  if (!cycle() && __type == "directed") {
    std::vector<T> top_sort = topological_sort();
    std::reverse(top_sort.begin(), top_sort.end());
    std::stack<T> s;
    std::unordered_map<T, int64_t> dist;
    for (auto &x : __elements) {
      dist[x] = INT_MAX;
    }
    dist[start] = 0;
    while (!top_sort.empty()) {
      auto current = top_sort.back();
      top_sort.pop_back();
      if (dist[current] != INT_MAX) {
        for (std::pair<T, int64_t> &x : adj[current]) {
          if (dist[x.first] > dist[current] + x.second) {
            dist[x.first] = dist[current] + x.second;
            top_sort.push_back(x.first);
          }
        }
      }
    }
    return (dist[end] != INT_MAX) ? dist[end] : -1;
  } else {
    std::unordered_map<T, int64_t> dist;
    for (auto &x : __elements) {
      dist[x] = INT_MAX;
    }
    std::priority_queue<std::pair<int64_t, T>,
                        std::vector<std::pair<int64_t, T>>,
                        std::greater<std::pair<int64_t, T>>>
        pq;
    pq.push(std::make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
      T currentNode = pq.top().second;
      T currentDist = pq.top().first;
      pq.pop();
      for (std::pair<T, int64_t> &edge : adj[currentNode]) {
        if (currentDist + edge.second < dist[edge.first]) {
          dist[edge.first] = currentDist + edge.second;
          pq.push(std::make_pair(dist[edge.first], edge.first));
        }
      }
    }
    return (dist[end] != INT_MAX) ? dist[end] : -1;
  }
  return -1;
}

template <typename T> std::vector<T> weighted_graph<T>::dfs(T start) {
  std::queue<T> q;
  std::vector<T> path;
  std::unordered_map<T, bool> visited;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int64_t size = q.size();
    for (int64_t i = 0; i < size; i++) {
      T current = q.front();
      path.push_back(current);
      q.pop();
      for (std::pair<T, int64_t> &x : adj[current]) {
        if (visited.find(x.first) == visited.end()) {
          q.push(x.first);
          visited[x.first] = true;
        }
      }
    }
  }
  return path;
}

template <typename T> std::vector<T> weighted_graph<T>::bfs(T start) {
  std::queue<T> q;
  std::vector<T> path;
  std::unordered_map<T, bool> visited;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int64_t size = q.size();
    for (int64_t i = 0; i < size; i++) {
      T current = q.front();
      path.push_back(current);
      q.pop();
      for (std::pair<T, int64_t> &x : adj[current]) {
        if (visited.find(x.first) == visited.end()) {
          q.push(x.first);
          visited[x.first] = true;
        }
      }
    }
  }
  return path;
}

template <typename T> int64_t weighted_graph<T>::connected_components() {
  auto explore = [&](std::unordered_map<T, bool> &visited, T element) -> void {
    std::stack<T> s;
    s.push(element);
    visited[element] = true;
    while (!s.empty()) {
      T current = s.top();
      s.pop();
      for (std::pair<T, int64_t> &x : adj[current]) {
        if (visited.find(x.first) == visited.end()) {
          s.push(x.first);
          visited[x.first] = true;
        }
      }
    }
  };
  size_t n = __elements.size();
  int64_t cc = 0;
  std::unordered_map<T, bool> visited;
  for (T x : __elements) {
    if (visited.find(x) == visited.end()) {
      explore(visited, x);
      cc++;
    }
  }
  return cc;
}

template <typename T> bool weighted_graph<T>::cycle() {
  std::unordered_map<T, int> indeg;
  std::queue<T> q;
  size_t visited = 0;

  for (T x : __elements) {
    for (std::pair<T, int64_t> &y : adj[x]) {
      indeg[y.first]++;
    }
  }

  for (T x : __elements) {
    if (indeg[x] == 0) {
      q.push(x);
    }
  }

  while (!q.empty()) {
    T current = q.front();
    q.pop();
    visited++;
    for (std::pair<T, int64_t> &x : adj[current]) {
      if (--indeg[x.first] == 0) {
        q.push(x.first);
      }
    }
  }
  return visited == 0;
}

template <typename T> std::vector<T> weighted_graph<T>::topological_sort() {
  std::vector<T> top_sort;
  std::unordered_map<T, bool> visited;
  std::unordered_map<T, int64_t> indeg;
  for (T x : __elements) {
    for (std::pair<T, int64_t> &y : adj[x]) {
      indeg[y.first]++;
    }
  }

  std::queue<T> q;
  for (T x : __elements) {
    if (indeg[x] == 0) {
      q.push(x);
      visited[x] = true;
    }
  }

  while (!q.empty()) {
    T current = q.front();
    q.pop();
    top_sort.push_back(current);
    for (std::pair<T, int64_t> &x : adj[current]) {
      if (visited.find(x.first) == visited.end()) {
        if (--indeg[x.first] == 0) {
          q.push(x.first);
          visited[x.first] = true;
        }
      }
    }
  }

  return top_sort;
}

template <typename T> int64_t weighted_graph<T>::prim(T __temp) {
  std::priority_queue<std::pair<T, int64_t>, std::vector<std::pair<T, int64_t>>,
                      std::greater<std::pair<T, int64_t>>>
      q;
  std::unordered_map<T, bool> visited;
  int64_t cost = 0;
  q.push(std::make_pair(0, __temp));
  while (!q.empty()) {
    std::pair<T, int64_t> current = q.top();
    q.pop();
    __temp = current.first;
    if (visited.find(__temp) != visited.end()) {
      continue;
    }
    cost += current.second;
    visited[__temp] = true;
    for (std::pair<T, int64_t> &x : adj[current.first]) {
      if (visited.find(x.first) == visited.end()) {
        q.push(x);
      }
    }
  }
  return cost;
}

template <typename T> bool weighted_graph<T>::bipartite(){
  std::unordered_map<T, int> color;
  std::queue<std::pair<T, int> > q;

  for(T x : __elements){
    if(color.find(x) == color.end()){
      q.push({x, 0});
      color[x] = 0;
      while(!q.empty()){
        std::pair<T, int> current = q.front();
        q.pop();
        T v = current.first;
        int col = current.second;
        for(std::pair<T, int64_t> & x : adj[v]){
          if(color.find(x.first) != color.end() && color[x.first] == col){
            return false;
          }
          if(color.find(x.first) == color.end()){
            color[x.first] = (col) ? 0 : 1;
            q.push({x.first, color[x.first]});
          }
        }
      }
    }
  }
  return true;
}

#endif
