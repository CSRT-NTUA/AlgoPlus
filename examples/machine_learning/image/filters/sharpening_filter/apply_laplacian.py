import matplotlib.pyplot as plt
import json
import os

if __name__ == "__main__":
    os.system("c++ -std=c++17 main.cc")
    os.system("./a.out")
    filename = open("results.json")
    file = json.load(filename)
    data = file['data']
    plt.imshow(data, cmap='gray')
    plt.show()
