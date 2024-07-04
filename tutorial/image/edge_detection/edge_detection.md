### Mini tutorial for sobel namespace
    --- We use sobel operator to perform edge detection. Sobel() function will return a 2d array with the resulted image

### **Perform edge detection with Sobel() function**:
```cpp
int main(){
  // data.json is the file that contains the 2d array of the image at "img" instance
  std::ifstream ifs("data.json");
  json jf = json::parse(ifs); 
  // 2d vector "data" has now the data of the image 
  std::vector<std::vector<int32_t> > data = jf["img"];

  // using the Sobel() function, passing the data as parameter, we perform edge detection. The results are saved at the 2d array "res"
  std::vector<std::vector<int32_t> > res = Sobel(data);
  json j;
  j["data"] = res;
  // we can optionally write the results in a file
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
# We just have to read from the results.json file and then plot the data with plt.imshow()
if __name__ == "__main__":
    os.system("c++ -std=c++17 main.cc")
    os.system("./a.out")
    filename = open("results.json")
    file = json.load(filename)
    data = file['data']
    plt.imshow(data, cmap='gray')
    plt.show()
```

### Mini tutorial for prewitt namespace
    --- We use prewitt operator to perform edge detection. Sobel() function will return a 2d array with the resulted image

### **Perform edge detection with Prewitt() function**:
```cpp
int main(){
  // data.json is the file that contains the 2d array of the image at "img" instance
  std::ifstream ifs("data.json");
  json jf = json::parse(ifs); 
  // 2d vector "data" has now the data of the image 
  std::vector<std::vector<int32_t> > data = jf["img"];

  // using the Sobel() function, passing the data as parameter, we perform edge detection. The results are saved at the 2d array "res"
  std::vector<std::vector<int32_t> > res = Prewitt(data);
  json j;
  j["data"] = res;
  // we can optionally write the results in a file
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
# We just have to read from the results.json file and then plot the data with plt.imshow()
if __name__ == "__main__":
    os.system("c++ -std=c++17 main.cc")
    os.system("./a.out")
    filename = open("results.json")
    file = json.load(filename)
    data = file['data']
    plt.imshow(data, cmap='gray')
    plt.show()
```