#include "dbscan.h"
#include <random>

int main(){
  std::vector<std::pair<double, double> > data; 

  for(int i = 0; i<100; i++){
    double rand1 = (rand() % 5) + 1;
    double rand2 = (rand() % 5) + 1;
    data.push_back({rand1, rand2});
  }


  for(int i = 0; i<100; i++){
    double rand1 = (rand() % 100) + 90;
    double rand2 = (rand() % 100) + 90;
    data.push_back({rand1, rand2});
  }
  DBSCAN a();
}
