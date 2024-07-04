### Mini tutorial for sharpening filter namespace
    --- apply_sharpening_filter() function applies a 3x3 laplacian mask to the passed image

### **How to perform the masking using apply_sharpening_filter() function**:
```cpp
int main() {
  // let's assume we have the data of the image in data.json file
  std::ifstream ifs("data.json");
  json jf = json::parse(ifs);
  // now 2d vector data has the data of the image
  std::vector<std::vector<int32_t>> data = jf["img"];
  Image img(data);
  // this applies the median filter to the image:img and saves the results to the res 2d array
  std::vector<std::vector<int32_t>> res = apply_sharpening_filter(img);
  json j;
  j["data"] = res;
  // we optionally write the results to a file
  std::ofstream file("results.json");
  file << j;
}
```

### **Visualize your results**:
```python
import matplotlib.pyplot as plt
import json
import os

# Visualization can easily be achieved using matplotlib
# We just open the file that we saved our results and plot the image
if __name__ == "__main__":
    os.system("c++ -std=c++17 main.cc")
    os.system("./a.out")
    filename = open("results.json")
    file = json.load(filename)
    data = file['data']
    plt.imshow(data, cmap='gray')
    plt.show()
```