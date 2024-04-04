#include "../../../src/machine_learning/regression/linear_regression/lin_reg.h"
#include <random>

std::vector<std::vector<double> > fill_data(){
  std::vector<std::vector<double> > data;  
  
  for(int i = 0; i<100; ++i){
    double rand1 = rand() % 5;
    data.push_back({double(i), rand1});
  }

  return data;
}

int main(){
  std::vector<std::vector<double> > data = fill_data();
  linear_regression l(data);

  std::pair<double, double> a_b = l.get_results();
  std::cout << "y = " << a_b.first << "x + " << a_b.second << '\n';

}
