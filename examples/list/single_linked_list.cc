#include "../../src/classes/list/linked_list.h"

int main(){
    linked_list<int> l;
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    l.push_back(10);
    l.push_back(0);
    l.visualize();
}