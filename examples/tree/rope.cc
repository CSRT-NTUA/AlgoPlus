#include "../../src/visualization/tree_visual/tree_visualization.h"
#include "../../src/classes/tree/rope.h"
#include <iostream>

using namespace std;

int main() {
    rope r("hello world");

    cout << r.inorder() << '\n';

    #define TREE_VISUALIZATION_H
    #ifdef TREE_VISUALIZATION_H
    r.visualize();
    #endif
}
