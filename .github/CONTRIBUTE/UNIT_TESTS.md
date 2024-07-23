### How do i write unit tests?

Writting unit tests is the most important part of contributing. Fortunately or not, this is a project about algorithms and a lot of edge cases exist, so we must make sure everything works as it should.


```cpp
#include "../catch2/catch.hpp"

TEST_CASE("testing this and that..."){
    std::vector<int> v = myclass.function();
    some mode code...
    std::vector<int> check_v = {the answer that myclass.function should return};
    REQUIRE(check_v == v);
}
```
