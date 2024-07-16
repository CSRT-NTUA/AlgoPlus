#ifndef AVERAGE_FILTER_H
#define AVERAGE_FILTER_H

#ifdef __cplusplus
#include <iostream>
#include "../image.h"
#endif


/**
* @brief average filter namespace
*/
namespace avg_filter {

  /**
  * @brief apply_avg_filter function: applies a 3x3 average filter to passed image: image
  * @param image(Class Image): the input image
  * @return vector<vector<int32_t> >: the resulted image after applying the average filter
  */
  std::vector<std::vector<int32_t> > apply_avg_filter(const std::vector<std::vector<int32_t> > &image){
    Image img(image);
    int height = img._height();
    int width = img._width();
    Image resulted_img(height, width);
    std::vector<std::vector<float> > kernel = {{1.0/9, 1.0/9, 1.0/9}, {1.0/9, 1.0/9, 1.0/9}, {1.0/9, 1.0/9, 1.0/9}};
    return img.apply_filter2d_float(kernel).get_2d_array();
  }
}

#endif
