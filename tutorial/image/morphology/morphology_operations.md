### Mini tutorial for morphology operations namespace
    --- dilate() function performs dilation to the passed image
    --- erote() function performs erotion to the passed image
    --- close() function performs closing to the passed image
    --- open() function performs opening to the passed image

### **How to apply the operations to images**:
```cpp
int main() {
  // let's assume we have the data of the image in data.json file 
  std::ifstream ifs("data.json");
  json jf = json::parse(ifs);
  // now 2d vector data has the data of the image
  std::vector<std::vector<int32_t>> data = jf["img"];
  Image img(data);
  // this applies the median filter to the image:img and saves the results to the res 2d array
  std::vector<std::vector<int32_t>> res = erote(img);
  std::vector<std::vector<int32_t>> res = dilate(img);
  std::vector<std::vector<int32_t>> res = open(img);
  std::vector<std::vector<int32_t>> res = close(img);
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
