#include <iostream>
#include "kmeans.h"
#include "../../../../third_party/json.hpp"

int main(){
  srand((unsigned)time(NULL));
  std::vector<std::vector<int64_t> > data;
  for(int i = 0; i<100; i++){
    int rand1 = (rand() % 5) + 0;
    int rand2 = (rand() % 5) + 0;
    data.push_back({rand1, rand2});
  }

  for(int i = 0; i<100; i++){
    int rand1 = (rand() % 50) + 40;
    int rand2 = (rand() % 50) + 40;
    data.push_back({rand1, rand2});
  }

  json j;
  j["data"] = data;
  kmeans a(data, 2);
  std::pair<std::vector<std::vector<int64_t> >, std::map<std::vector<int64_t> ,int64_t> > ans = a.run();
  j["centroids"] = ans.first;
  j["assignments"] = ans.second;
  std::ofstream file("info.json");
  file << j;
}
