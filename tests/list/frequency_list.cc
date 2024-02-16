#include "../../src/classes/list/frequency_list.h"
#include "../catch2/catch.hpp"

TEST_CASE("Testing empty() and push_front() frequency_list") {
    frequency_list<int> flist;

    REQUIRE(flist.empty() == true);
    flist.push_front(5);
    REQUIRE(flist.empty() == false);
}

TEST_CASE("Testing push_back() frequency_list") {
    frequency_list<int> flist;

    flist.push_back(7);
    REQUIRE(flist.get_frequency(7) == 1);
}

TEST_CASE("Testing search() frequency_list") {
    frequency_list<int> flist;

    flist.push_front(7);
    REQUIRE(flist.search(7) == true);
    REQUIRE(flist.search(8) == false);
}

TEST_CASE("Testing erase() frequency_list") {
    frequency_list<int> flist;

    flist.push_back(10);
    flist.erase(10);
    REQUIRE(flist.search(10) == false);
}

TEST_CASE("Testing functionality in unison frequency_list") {
    frequency_list<int> flist;

    flist.push_back(1);
    flist.push_back(1);
    flist.push_front(2);
    flist.push_front(2);
    flist.push_front(2);

    REQUIRE(flist.get_frequency(1) == 2);
    REQUIRE(flist.get_frequency(2) == 3);

    flist.erase(1);
    REQUIRE(flist.search(1) == false);
    REQUIRE(flist.search(2) == true);
}