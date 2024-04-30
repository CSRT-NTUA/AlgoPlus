import json
import matplotlib.pyplot as plt
import os
import numpy as np

def fill_data():
    #data = []
    #for i in range(400):
    #    data.append([i, i**2])
    data = [[1, 45000], [2, 50000], [3,  60000], [4, 80000], [5, 110000], [6, 150000], [7, 200000]]
    return data

def plot(data,a,b):
    for x,y in data:
        plt.scatter(x,y,color='blue')
    x = np.linspace(0, 400, num = 400)
    fx = []
    for i in range(len(x)):
        fx.append(a + b*i)
    print(fx)
    plt.plot(x, fx)
    plt.grid()
    plt.show()

       
# This is just a template, if you want more clusters please fill more colors to the COLORS list
if __name__ == "__main__":
    # here you should fill the data
    # parser should be better here(or add an option for parser)
    data = fill_data()
    data_dict = {
            "data":data
            }
    json_object = json.dumps(data_dict)
    
    with open("data.json", "w") as outfile:
        outfile.write(json_object)
    
    # run the kmeans clustering with CLUSTERS clusters
    os.system(f"c++ -std=c++17 poly_reg.cc")
    os.system("./a.out")
    
    input_name = open("info.json", 'r') 
    file = json.load(input_name)
    coeffs = file["coeffs"]
    print(f"Coefficients are {coeffs}")
    
