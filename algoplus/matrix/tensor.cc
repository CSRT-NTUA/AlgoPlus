#ifdef __cplusplus
#include <vector>
#endif

struct _3d_matrix{
  std::vector<std::vector<std::vector<int64_t> > > mat;
  int64_t dim1, dim2, dim3;
};

class tensor{
public:
  explicit tensor(int64_t dim1, int64_t dim2, int64_t dim3){
    matrix.dim1 = dim1;
    matrix.dim2 = dim2;
    matrix.dim3 = dim3;
    matrix.mat.resize(dim1, std::vector<std::vector<int64_t> >(dim2, std::vector<int64_t>(dim3)));  
  }

  ~tensor() {}
  
private:
  _3d_matrix matrix;
};
