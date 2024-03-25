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

/**
  * @brief DBSCAN clustering algorithm class
  */
class DBSCAN{
private:
  std::vector<std::pair<double, double>> setOfPoints;
  double Eps;
  int64_t MinPts;
  int64_t cluster_id;
  std::map<std::pair<double, double>, int64_t> points;

public:
  
  /**
  * @brief constructor for the DBSCAN class
  * @param setOfPoints vector<pair<double,double>>: the input dataset
  * @param Eps: the input diameter 
  * @param MinPts: the minimum points that a cluster should have to exist
  */
  explicit DBSCAN(std::vector<std::pair<double, double>> setOfPoints, double Eps, int64_t MinPts) noexcept : setOfPoints(setOfPoints), Eps(Eps), MinPts(MinPts){
    // cluster_id is by default noise
    cluster_id = 0;
    for(size_t i = 0; i<setOfPoints.size(); ++i){
      if(points.find(setOfPoints[i]) == points.end()){
        if(ExpandCluster(setOfPoints, setOfPoints[i], cluster_id, Eps, MinPts)){
          cluster_id = nextId(cluster_id);
        }
      }
    }
  }
  
  /**
  * @ brief nextId function
  * @ return int64_t: the next cluster id
  */
  int64_t nextId(int64_t cluster_id);

  /**
  * @brief ExpandCluster function
  * @param setOfPoints: the input dataset 
  * @param point: the input point 
  * @param cluster_id: the input cluster_id
  * @param Eps: the input diameter 
  * @param MinPts: the minimum points that a cluster should have to exist
  *
  */
  bool ExpandCluster(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, int64_t cluster_id, double Eps, int64_t MinPts);
  
  /**
  * @brief get_query function
  * @param setOfPoints: the input dataset
  * @param point: the input point
  * @param Eps: the input diameter
  *
  */
  std::vector<std::pair<double, double> > get_query(std::vector<std::pair<double, double> > setOfPoints, std::pair<double, double> point, double Eps);
  
  /**
  * @brief dist function
  * @param a: the first input vector
  * @param b: the second input vector
  * @return double: the euclidean distance of vector a and b
  */ 
  double dist(std::pair<double, double> a, std::pair<double, double> b);
  
  /**
  * @brief get_clusters function
  * @return map<pair<double,double>>: the points and their assignments
  *
  */
  std::map<std::pair<double, double>, int64_t> get_clusters();
  
  /**
  * @brief get_noise function
  * @return vector<pair<double,double>>: the total points that exist as noise in the dataset
  */
  std::vector<std::pair<double, double> > get_noise();
};

#endif
