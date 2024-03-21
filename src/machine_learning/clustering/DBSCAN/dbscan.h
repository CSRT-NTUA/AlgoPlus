#pragma once
#ifndef DBSCAN_H 
#define DBSCAN_H 

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <utility>
#include <cstdint>
#endif


class DBSCAN{
private:
  std::vector<std::pair<double, double>> setOfPoints;
  double Eps;
  int64_t MinPts;
  int64_t cluster_id;
  std::map<std::pair<double, double>, int64_t> points;

public:

  explicit DBSCAN(std::vector<std::pair<double, double>> setOfPoints, double Eps, int64_t MinPts) noexcept : setOfPoints(setOfPoints), Eps(Eps), MinPts(MinPts){
    // cluster_id is by default noise
    cluster_id = 0;
    for(size_t i = 0; i<setOfPoints.size(); ++i){
      std::cout << "checking point " << setOfPoints[i].first << " " << setOfPoints[i].second << '\n';
      if(points.find(setOfPoints[i]) == points.end()){
        if(ExpandCluster(setOfPoints, setOfPoints[i], cluster_id, Eps, MinPts)){
          cluster_id = nextId(cluster_id);
        }
      }
    }
  }

  int64_t nextId(int64_t cluster_id);

  bool ExpandCluster(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, int64_t cluster_id, double Eps, int64_t MinPts);

  std::vector<std::pair<double, double> > get_query(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, double Eps);

  double dist(std::pair<double, double> a, std::pair<double, double> b);

  std::map<std::pair<double, double>, int64_t> get_clusters();

  std::vector<std::pair<double, double> > get_noise();
};

#endif
