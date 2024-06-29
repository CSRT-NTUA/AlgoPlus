#ifndef SOBEL_OPERATOR_H
#define SOBEL_OPERATOR_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
#include <cmath>
#endif

/**
* @brief Sobel operator is used for edge detection. It creates 2 3x3 arrays G_x and G_y and apply them 
* to an image A(G_x * A, G_y * A). After that, the resulting image with edge detection is G = sqrt(G_x^2 + G_y^2)
*/
namespace sobel{
  /**
  * @ brief kernel function. Of course you can change the kernel values depending on your needs  
  * @return pair<vector<int32_t>, vector<int32_t>> the G_x and G_y 3x3 kernels
  */
  std::pair<std::vector<std::vector<int32_t> >, std::vector<std::vector<int32_t> > > kernel(){
    std::vector<std::vector<int32_t> > G_x = { {1, 0, -1}, {2, 0, -2}, {1, 0, -1} };
    std::vector<std::vector<int32_t> > G_y = { {1, 2, 1}, {0, 0, 0}, {-1, -2, -1} };
    return std::make_pair(G_x, G_y);
  }

  /**
   * @brief power_2 function
   * @param G: the input 2d array 
   * @return vector<vector<int32_t> > the array squared powered
   */
  std::vector<std::vector<int32_t> > power_2(const std::vector<std::vector<int32_t> > &G){
    int height = G.size();
    int width = G[0].size();
    std::vector<std::vector<int32_t> > GP(height, std::vector<int32_t>(width));
    for(int i = 0; i<height; i++){
      for(int j = 0; j<height; j++){
        GP[i][j] = G[i][j]*G[i][j];
      }
    }
    return GP;
  }
  
  /**
   * @brief square function
   * @param G the input 2d array
   * @return vector<vector<int32_t> > the squared root 2d array
   */
  std::vector<std::vector<int32_t> > square(const std::vector<std::vector<int32_t> > &G){
    int height = G.size();
    int width = G[0].size();
    std::vector<std::vector<int32_t> > res_img(height, std::vector<int32_t>(width));
    for(int i = 0; i<height; i++){
      for(int j = 0; j<width; j++){
        res_img[i][j] = sqrt(G[i][j]);
      }
    }
    return res_img;
  }
  
  /**
   * @brief add function
   * @param a the first input 2d array 
   * @param b the second input 2d array 
   * @return vector<vector<int32_t> > the sum of the 2 arrays
   */
  std::vector<std::vector<int32_t> > __add(const std::vector<std::vector<int32_t> > &a, const std::vector<std::vector<int32_t> > &b){
    assert(a.size() == b.size());
    assert(a[0].size() == b[0].size());
    int height = a.size();
    int width = a[0].size();
    std::vector<std::vector<int32_t> > res(height, std::vector<int32_t>(width));
    for(int i = 0; i<height; i++){
      for(int j = 0; j<width; j++){
        res[i][j] = a[i][j] + b[i][j];
      }
    }
    return res;
  }
  
  /**
  * @brief Sobel apply function
  * @param image: the 2d array of the input image 
  * @return vector<vector<in t32_t> > the resulting image
  */
  std::vector<std::vector<int32_t> > Sobel(const std::vector<std::vector<int32_t> > &image) {
    int height = image.size();
    int width = image[0].size();

    std::pair<std::vector<std::vector<int32_t> >, std::vector<std::vector<int32_t> > > kernels = kernel();
    std::vector<std::vector<int32_t> > k1 = kernels.first; std::vector<std::vector<int32_t> > k2 = kernels.second;
    std::vector<std::vector<int32_t> > G_x(height, std::vector<int>(width));
    std::vector<std::vector<int32_t> > G_y(height, std::vector<int>(width));


    for(int x = 0; x < height; x++){
      for(int y = 0; y < width; y++){
        G_x[x][y] = image[x][y]*k1[1][1];
        if(y - 1 >= 0){
          G_x[x][y] += image[x][y - 1]*k1[1][0];
        }
        if(y + 1 < width){
          G_x[x][y] += image[x][y + 1]*k1[1][2];
          if(x + 1 < height){
            G_x[x][y] += image[x + 1][y + 1]*k1[2][2];
          }
        }
        if(x - 1 >= 0){
          G_x[x][y] += image[x - 1][y]*k1[0][1];
          if(y + 1 < width){
            G_x[x][y] += image[x - 1][y + 1]*k1[0][2];
          }
          if(y - 1 >= 0){
            G_x[x][y] += image[x - 1][y - 1]*k1[0][0];
          }
        }
        if(x + 1 < height){
          G_x[x][y] += image[x + 1][y]*k1[2][1];
          if(y - 1 >= 0){
            G_x[x][y] += image[x + 1][y - 1]*k1[2][0];
          }
        }

        G_y[x][y] = image[x][y]*k2[1][1];
        if(y - 1 >= 0){
          G_y[x][y] += image[x][y - 1]*k2[1][0];
        }
        if(y + 1 < width){
          G_y[x][y] += image[x][y + 1]*k2[1][2];
          if(x + 1 < height){
            G_y[x][y] += image[x + 1][y + 1]*k2[2][2];
          }
        }
        if(x - 1 >= 0){
          G_y[x][y] += image[x - 1][y]*k2[0][1];
          if(y + 1 < width){
            G_y[x][y] += image[x - 1][y + 1]*k2[0][2];
          }
          if(y - 1 >= 0){
            G_y[x][y] += image[x - 1][y - 1]*k2[0][0];
          }
        }
        if(x + 1 < height){
          G_y[x][y] += image[x + 1][y]*k2[2][1];
          if(y - 1 >= 0){
            G_y[x][y] += image[x + 1][y - 1]*k2[2][0];
          }
        }
      }
    }

    G_x = power_2(G_x);
    G_y = power_2(G_y);

    std::vector<std::vector<int32_t> > G = __add(G_x, G_y);
    return square(G);
  }
}


#endif  
