#include <iostream>
#include "timer.h"
#include "debug.h"
#include "../classes/graph/graph.h"

int main() {
    weighted_graph<int> g("directed");
    g.add_edge(0, 1, 5);
    g.add_edge(1, 2, 4);
    g.add_edge(2, 3, 5);
    g.add_edge(3, 4, 2);
    g.add_edge(4, 5, 1);
    auto y_combinator = [&](int a, int b) -> double {
        return g.shortest_path(a, b);
    };

    auto y_combinator2 = [&](int a) -> std::vector<int> {
        return g.dfs(a);
    };

    // auto bound_dfs = std::bind(&graph<int>::dfs, &g, std::placeholders::_1);
    TIMER::exec_time(y_combinator, 0, 4);
    DEBUG::get_args(y_combinator, 0, 2, 3, 4, 'a');

    std::cout << TIMER::check_faster(y_combinator,std::make_tuple(0, 1), y_combinator2, std::make_tuple(0)) << '\n';
}
