#include "../../src/visualization/tree_visual/tree_visualization.h"
#include "../../src/classes/tree/rope.h"
#include <iostream>

using namespace std;

int main() {
    rope r("hello world", 3);

    cout << r.inorder() << '\n';

    r.visualize();
}
