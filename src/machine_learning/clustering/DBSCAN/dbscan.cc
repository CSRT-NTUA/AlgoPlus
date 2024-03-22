#include "dbscan.h"

int64_t DBSCAN::nextId(int64_t cluster_id){
  cluster_id++;
  return cluster_id;
}

bool DBSCAN::ExpandCluster(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, int64_t cluster_id, double Eps, int64_t MinPts){
  std::vector<std::pair<double, double> > seeds = get_query(setOfPoints, point, Eps);
  if(seeds.size() < MinPts){
    // no core point 
    points[point] = -1;
    return false;
  }
  else{
    // we have a core point
    // all the points in seeds are density-reachable from point
    for(auto & x : seeds){
      points[x] = cluster_id;
    }
    for(auto it = seeds.begin(); it != seeds.end(); it++){
      if((*it).first == point.first && (*it).second == point.second){
        seeds.erase(it);
        break;
      }
    }

    while(!seeds.empty()){
      auto current = seeds[0];
      std::vector<std::pair<double, double> > result = get_query(setOfPoints, current, Eps);

      if(result.size() >= MinPts){
        for(size_t i = 0; i<result.size(); i++){
          std::pair<double, double> result_p = result[i];
          if(points.find(result_p) == points.end() || points[result_p] == -1){
            if(points.find(result_p) == points.end()){
              seeds.push_back(result_p);
            }
            points[result_p] = cluster_id;
          } // unclassified or noise
        }      
      }
      for(auto it = seeds.begin(); it != seeds.end(); it++){
        if((*it).first == current.first && (*it).second == current.second){
          seeds.erase(it);
          break;
        }
      }
    }
    return true;
  }
  return false;
}

std::vector<std::pair<double, double> > DBSCAN::get_query(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, double Eps){
  std::vector<std::pair<double, double> > ans;
  for(size_t i = 0; i<setOfPoints.size(); i++){
    std::pair<double, double> curr = setOfPoints[i];
    if(dist(point, curr) <= Eps){
      std::cout << "Distance of {" << point.first << "," << point.second << "} and {" << curr.first << "," << curr.second << "} is smaller than " << Eps << '\n';
      ans.push_back(curr);
    }
  }
  return ans;
}

double DBSCAN::dist(std::pair<double, double> a, std::pair<double, double> b){
  return sqrt( pow(b.second - a.second, 2) + pow(b.first - a.first, 2) );
}

std::map< std::pair<double, double>, int64_t> DBSCAN::get_clusters(){
  std::map< std::pair<double, double>, int64_t> ans;
  std::cout <<  "There are " << cluster_id << " clusters" << '\n';
  for(size_t i = 0; i<setOfPoints.size(); i++){
    if(points[setOfPoints[i]] != -1){
      ans[setOfPoints[i]] = points[setOfPoints[i]];
    }
  }
  return ans;
}

std::vector< std::pair<double, double>> DBSCAN::get_noise(){
  std::vector< std::pair<double, double> > ans;
  for(size_t i = 0; i<setOfPoints.size(); i++){
    if(points[setOfPoints[i]] == -1){
      ans.push_back(setOfPoints[i]);
    }
  }
  return ans;
}

