#include "../../src/classes/heap/min_heap.h"
#include "../../third_party/catch.hpp"

TEST_CASE("testing insertion an minimum")
{
    min_heap<int> heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    REQUIRE(heap.min() == 1);
}

TEST_CASE("testing removal")
{
    min_heap<int> heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.remove(3);
    REQUIRE(heap.min() == 1);
}

TEST_CASE("testing decreasing key")
{
    min_heap<int> heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.decrease_key(2, 0);
    REQUIRE(heap.min() == 0);
}

TEST_CASE("testing copy constructor"){
    min_heap<int> heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    min_heap<int> heap2(heap);
    REQUIRE(heap2.min() == 1);   
}


