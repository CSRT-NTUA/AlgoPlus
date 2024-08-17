#include <print>
#include <vector>
#include <utility>
#include <format>
#include <optional>
#include <ctime>
#include <set>
#include <map>
#include <ranges>
#include <algorithm>
#include <expected>
#include "containers/bubble.h"

using namespace std;

std::optional<std::vector<int>> func(const int &x) {
    std::vector<int> v;
    for(int i = x; i < x + 15; i++){
        v.push_back(i);
    }
    return v;
}

int func(int &&x) {
    x += 5;
    return std::move(x);
}

int main() {
    bubble<char, 5> b;
    b.insert('a', 'b', 'c', 'd', 'e');
    std::cout << b << '\n';
    b.remove('b');
    std::cout << b << '\n';
    // std::vector v {1, 2, 3, 4, 5};
    // auto it = std::ranges::lower_bound(v, 2, [](const int &a, const int &b){ return a < b; });
    // std::cout << std::distance(std::ranges::begin(v), it) << '\n';
}
// int main() {
//     //std::vector<std::pair<int, int>> v {{1,2}, {2,3}, {3,4}};
//     //std::vector<int> v2 {1, 2, 3, 4, 5};
//
//     //std::map<std::string, int> m;
//     //m["spiros"] = 10;
//     //m["hello"] = 20;
//
//     std::vector v {1, 2, 3, 4, 5, 6};
//     // std::set s { v
//     //     | std::ranges::to<std::set<int>>()
//     // };
//
//     // std::print("{}", s);
//     auto res { v
//         | std::views::filter([](int &x) { return x % 2 == 0; })
//         | std::views::transform([](int &x) { return x *= 2; })
//     };
//     std::vector<int> vec2 = std::ranges::to<std::vector>(res);
//     //
//     std::ranges::sort(vec2);
//     // std::print("{}", vec2);
//
//     std::string s { "Hello there my name is spiros" };
//
//     auto words = { s
//         | std::views::split(' ')
//         | std::views::transform([](const auto &v){ return std::string {std::from_range, v}; })
//         | std::ranges::to<std::vector>()
//     };
//     int x = 10;
//     func(x);
//     std::println("{}", x);
//
//     std::expected<int, std::string> e { 19 };
//     if(e.value() < 20) {
//         e = std::unexpected("Error, value < 20");
//     }
//     if(e.has_value()){
//         std::println("{}", e.value());
//     }
//     else{
//         std::println("{}", e.error());
//     }
//
//     // int&& y = std::move(x);
//
//     // std::vector v {1, 2, 3, 4, 5};
//
//     // auto start = std::clock();
//     // std::println("{}", std::find(begin(v), end(v), 2) != end(v));
//     // auto end = std::clock();
//     // std::println("Time to execute {}", end - start);
//
//     // start = std::clock();
//     // std::println("{}", std::ranges::find(v, 2) != std::ranges::end(v));
//     // end = std::clock();
//     // std::println("Time to execute {}", end - start);
//
//     // auto r11 { std::views::repeat(2, 3) };
//     // auto r22 { std::views::iota(10) };
//     // auto r33 { std::views::repeat(10) };
//
//
//     // std::println("{}", r11);
// }
