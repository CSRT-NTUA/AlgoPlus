#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#ifdef _cplusplus
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
#endif


/*
 * @param graph - An adjacency unordered_map containing directed edges forming the graph
 * @param start - The id of the starting node
 * 
 * @details - An implementation of the Bellman-Ford algorithm. The algorithm finds the shortest path between
 * a starting node and all other nodes in the graph. The algorithm also detects negative cycles.
 * If a node is part of a negative cycle then the minimum cost for that node is set to
 * Double.NEGATIVE_INFINITY.
 */
template <typename T>
std::unordered_map<T, double> BellmanFord(std::unordered_map<T, std::vector<std::pair<T, double>>> &graph, T start){
    
    std::unordered_map<T, double> dist;
    // Initialize the distance to all nodes to be infinity
    // except for the starting node which is zero.
    for(auto it: graph)
        dist[it.first] = std::numeric_limits<double>::infinity();
    dist[start] = 0;
    
    //Get number of vertices present in the graph
    int v = graph.size();

    // For each vertex, apply relaxation for all the edges
    for(int i=0; i<v-1; i++)
        for(const auto j: graph)
            for(const auto edge: graph[j.first])
                if(dist[j.first]+edge.second < dist[edge.first])
                    dist[edge.first] = dist[j.first]+edge.second;

    // Run algorithm a second time to detect which nodes are part
    // of a negative cycle. A negative cycle has occurred if we
    // can find a better path beyond the optimal solution.
    for(int i=0; i<v-1; i++)
        for(const auto j: graph)
            for(const auto edge: graph[j.first])
                if(dist[j.first]+edge.second < dist[edge.first])
                    dist[edge.first] = -std::numeric_limits<double>::infinity();

    // Return the array containing the shortest distance to every node
    return dist;
    
}

#endif