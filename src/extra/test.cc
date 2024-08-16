#include "table.h"
#include <ranges>

using namespace std;

int main() {
    table<int> t;
    t.push_front(20, 10);
    t.push_back(30, 40, 50);
    cout << t.size() << '\n';
    std::vector v { t.vectorize() };
    for(int i = 0; i<t.size(); i++){
        cout << t[i] << " ";
    }
    cout << '\n';
    // auto res = { t
    //     | std::views::transform([](const auto &val) { return val % 2 == 0; })
    // };
}
