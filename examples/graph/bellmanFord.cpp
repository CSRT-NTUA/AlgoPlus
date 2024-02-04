#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<limits>
#include "../../src/algorithms/graph/bellmanFord.h"

int main(){
    std::unordered_map<char, std::vector<std::pair<char, double>>> graph;
    graph['a'].push_back(std::make_pair('b', 1));
    graph['b'].push_back(std::make_pair('c', 1));
    graph['b'].push_back(std::make_pair('f', 4));
    graph['b'].push_back(std::make_pair('g', 4));
    graph['c'].push_back(std::make_pair('e', 1));
    graph['d'].push_back(std::make_pair('c', 1));
    graph['e'].push_back(std::make_pair('d', -3));
    graph['f'].push_back(std::make_pair('g', 5));
    graph['f'].push_back(std::make_pair('h', 3));
    graph['g'].push_back(std::make_pair('h', 4));


    char start = 'a';
    std::unordered_map<char, double> dist = BellmanFord(graph, 'a');

    for(auto it: dist)
        printf("The cost to get from node %c to %c is %.2f\n", start, it.first, it.second);

    // Output: 
    // The cost to get from node a to h is 0.00
    // The cost to get from node a to a is 0.00
    // The cost to get from node a to b is 1.00
    // The cost to get from node a to c is -inf
    // The cost to get from node a to d is -inf
    // The cost to get from node a to e is -inf
    // The cost to get from node a to f is 5.00
    // The cost to get from node a to g is 5.00

    return 0;
}
