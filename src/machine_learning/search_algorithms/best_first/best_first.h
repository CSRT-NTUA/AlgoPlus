#pragma once
#ifndef BEST_FIRST_H 
#define BEST_FIRST_H 

#ifdef __cplusplus
#include <iostream>
#include <unordered_map>
#include <queue>
#endif

/**
* @brief best first class
*/
template <typename T> class best_first{
private:
  std::unordered_map<T, std::vector<std::pair<T, double> > > adj; 
  std::unordered_map<T, double> nodes;
  
public:

  /**
   * @brief best_first constructor
   * @param v: unordered_map<T, pair<T, int64_t> > initializer vector. Default = {}
   *
   */
  explicit best_first(std::unordered_map<T, std::vector<std::pair<T, double> > > v = {}){
    if(!v.empty()){
      this->adj = v;
    }
  }
  
  /**
  * @brief insert_node function
  * @param u: the node ID
  * @param val: the heuristic value of node u
  */
  void insert_node(T u, double val){
    nodes[u] = val;
  }


  /**
   * @brief has_edge function
   * @param u: the first node
   * @param v: the second node
   * @return true if there exist an edge between u and v
   * @return false otherwise
   */
  bool has_edge(T u, T v){
    if(adj.find(u) != adj.end()){
      for(std::pair<T, double> &x : adj[u]){
        if(x.first == v){
          return true;
        }
      }
    }
    return false;
  }
 
  /**
   * @brief add_edge function
   * @param u: the first node
   * @param v: the second node
   */
  void add_edge(T u, T v){
    try{
      if(nodes.find(u) != nodes.end() && nodes.find(v) != nodes.end()){
        adj[u].push_back(std::make_pair(v, nodes[v]));
      }
      else{
        throw std::logic_error("One of the two nodes that passed to the function do not exist in the graph");
      }
    }
    catch(std::logic_error &e){
      std::cerr << e.what() << '\n';
    }
  }
  
  /**
   * @brief search function
   * @param start: starting node
   * @param end: end node
   * @return true if search found the end node.
   * @return false otherwise
   */
  bool search(T start, T end){
    if(adj.empty()){
      return false;
    }
    std::unordered_map<T, bool> visited;
    std::priority_queue<std::pair<T, double>, std::vector<std::pair<T, double> >, std::greater<std::pair<T, double> > > q;
    q.push({start, nodes[start]});
    visited[start] = true;
    while(!q.empty()){
      int64_t size = q.size();
      for(int64_t i = 0; i<size; i++){
        std::pair<T, double> current = q.top();
        std::cout << current.first << " " << current.second << '\n';
        if(current.first == end){
          return true;
        }
        q.pop();
        for(std::pair<T, double> &x: adj[current.first]){
          if(visited.find(x.first) == visited.end() && x.second <= nodes[current.first]){
            visited[x.first] = true;
            q.push({x.first, nodes[x.first]});
          }
        }
      }
    }
    return false;
  }
};


#endif

