#include "image.h"

int main(){
    std::vector<std::vector<int32_t> > data = {{1,2,3}, {4,5,6}, {7,8,9}};
    Image img(data);
    img = img.resize(img);
}