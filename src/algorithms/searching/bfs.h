#pragma once
#ifndef BFS_H
#define BFS_H

#ifdef __cplusplus
#include <vector>
#include <queue>
#include <unordered_set>
#endif

/**
 * @brief Breadth First Search (BFS) algorithm
 *
 * @param graph The graph to search
 * @param start The starting node
 * @param key The key to search for
 * @return T The key if found
 * if not found, returns T{} (default value of T)
 */
template <typename T>
T bfs(const std::vector<std::vector<T>> &graph, T start, T key)
{
    std::unordered_set<T> visited;
    std::queue<T> queue;

    visited.insert(start);
    queue.push(start);
    if (graph.empty() || graph[start].empty())
    {
        return T{};
    }
    else if (start == key)
        return start;

    while (!queue.empty())
    {
        T current = queue.front();
        queue.pop();

        if (current == key)
            return current;

        for (T neighbor : graph[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }

    return T{}; // Not found
}

#endif
