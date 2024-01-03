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
  graph(std::string __type) {
    try {
      if (__type == "directed" || __type == "undirected") {
        this->__type = __type;
      } else {
        throw std::invalid_argument("Can't recognize the type of graph");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }
  ~graph() {}

  void add_edge(T u, T v, int64_t w) {
    if (__type == "undirected") {
      adj[u].push_back(v);
      adj[v].push_back(u);
    } else {
      adj[u].push_back(v);
    }
  }

  std::vector<T> dfs(T start) {
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

  std::vector<T> bfs(T start) {
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

private:
  std::unordered_map<T, T> adj;
  std::string __type;
};

template <typename T> class weighted_graph {
public:
  weighted_graph(std::string __type) {
    try {
      if (__type == "directed" || __type == "undirected") {
        this->__type = __type;
      } else {
        throw std::invalid_argument("Can't recognize the type of graph");
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

  std::vector<T> dfs(T start) {
    std::stack<T> s;
    std::vector<T> path;
    std::unordered_map<T, bool> visited;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
      T current = s.top();
      path.push_back(current);
      s.pop();
      for (std::pair<T, int64_t> &x : adj[current]) {
        if (visited.find(x.first) == visited.end()) {
          s.push(x.first);
          visited[x.first] = true;
        }
      }
    }
    return path;
  }

  std::vector<T> bfs(T start) {
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

  int64_t dijkstra(T start, T end){
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

private:
  std::unordered_map<T, std::vector<std::pair<T, int64_t>>> adj;
  std::string __type;
  std::unordered_set<T> __elements;
};

