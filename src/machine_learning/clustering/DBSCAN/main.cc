#include "dbscan.h"
#include <fstream>
#include <random>
#include "../../../../third_party/json.hpp"

using nlohmann::json;

int main(){
  srand((unsigned)time(NULL));
  json j;
  std::vector<std::pair<double, double> > data = {{1,2}, {2,3}, {2.5, 3.5}, {100,101}, {101,102}, {101.5, 102.3}}; 
  j["data"] = data;
  DBSCAN a(data, 4, 3);

  std::map<std::pair<double, double>, int64_t>  clusters = a.get_clusters(); 
  std::vector<std::pair<double, double> > noise = a.get_noise();
  j["noise"] = noise;

  for(auto & x : clusters){
    std::cout << "[" << x.first.first << " " << x.first.second << "]" << ": " << x.second << '\n';
  }
  j["centroids"] = clusters;
  std::ofstream file("info.json");
  file << j;

}
