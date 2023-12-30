#ifdef __cplusplus
#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
#include <string>
#include <stack>
#endif

template <typename T>
class graph{
public:
  graph(std::string __type){
    try{
      if(__type == "directed" || __type == "undirected"){
        this -> __type = __type;
      }
      else{
        throw std::invalid_argument("Can't recognize the type of graph");
      }
    }
    catch(std::invalid_argument& e){
      std::cerr << e.what() << '\n';
      return;
    }
  }
  ~graph(){
    adj.clear();
  }

  void add_edge(T u, T v, int64_t w){
    if(__type == "undirected"){
      adj[u].push_back(std::make_pair(v, w));
      adj[v].push_back(std::make_pair(u, w));
    }
    else if(__type == "directed"){
      adj[u].push_back(std::make_pair(v , w));
    }
  }
 
  std::vector<T> dfs(T start){
    std::stack<T> s;
    std::vector<T> path;
    std::unordered_map<T, bool> visited;
    s.push(start);
    visited[start] = true;
    while(!s.empty()){
      T current = s.top();
      path.push_back(current);
      s.pop();
      for(std::pair<T, int64_t> &x: adj[current]){
        if(visited.find(x.first) == visited.end()){
          s.push(x.first);
          visited[x.first] = true;
        }
      }
    }
    return path;
  }

  std::vector<T> bfs(T start){
    std::queue<T> q;
    std::vector<T> path;
    std::unordered_map<T, bool> visited;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
      int64_t size = q.size();
      for(int64_t i = 0; i<size; i++){
        T current = q.front();
        path.push_back(current);
        q.pop();
        for(std::pair<T, int64_t> &x: adj[current]){
          if(visited.find(x.first) == visited.end()){
            q.push(x.first);
            visited[x.first] = true;
          }
        }
      }
    }
    return path;
  }

private:
  std::unordered_map<T, std::vector<std::pair<T, int64_t> > > adj;
  std::string __type;
};

int main(){
  graph<int> g("usdirected");
  g.add_edge(0 , 1, 3);
  g.add_edge(1, 2, 4);
  g.add_edge(0 , 2, 5);
  std::vector<int> v = g.dfs(0);
  for(auto & x : v){
    std::cout << x << '\n';
  }

}
