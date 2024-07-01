#include "../../../../../src/machine_learning/image/filters/median_filter.h"
#include "../../../../../third_party/json.hpp"
#include <fstream>
#include <iostream>

using namespace median_filter;
using namespace std;
using namespace nlohmann;

int main() {
  std::ifstream ifs("data.json");
  json jf = json::parse(ifs);
  std::vector<std::vector<int32_t>> data = jf["img"];
  Image img(data);
  std::vector<std::vector<int32_t>> res = apply_median_filter(img);
  if (res.empty()) {
    cout << "empty" << '\n';
  }
  json j;
  j["data"] = res;
  std::ofstream file("results.json");
  file << j;
}
