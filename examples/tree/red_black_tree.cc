#ifdef __cplusplus
#include "../../src/classes/tree/red_black_tree.h"
#include <iostream>
#endif

int main() {
    red_black_tree<char> rb({'a','b','c'});
    rb.insert('d');
    rb.insert('t');
    rb.remove('b');
    // Will print an inorder traversal.
    cout<<rb<<std::endl;

    // Will return a preorder traversal.
    std::vector<char> v = rb.preorder();
    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<" ";
    std::cout<<std::endl;

    
    // example for visualise.
    red_black_tree<int> rb({1, 2, 3, 4, 5, 6, 7, 8, 9});
    rb.visualize();
    return 0;
}