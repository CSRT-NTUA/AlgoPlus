#pragma once
#ifndef DFS_H
#define DFS_H

#ifdef __cplusplus
#include <vector>
#include <unordered_set>
#endif

/**
 * @brief Depth First Search (DFS) algorithm
 *
 * @param graph The graph to search
 * @param start The starting node
 * @param visited The set of visited nodes
 * @param key The key to search for
 * @return T The key if found
 * if not found, returns T{} (default value of T)
 */
template <typename T>
T dfs(const std::vector<std::vector<T>> &graph, T start, std::unordered_set<T> &visited, T key)
{
    visited.insert(start);

    if (start == key)
        return start;
    for (int neighbor : graph[start])
    {
        if (visited.find(neighbor) == visited.end())
        {
            T res = dfs(graph, neighbor, visited, key);
            if (res != T{})
            {
                return res;
            }
            dfs(graph, neighbor, visited);
        }
    }
    return T{}; // Not found
}

#endif