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

def plot(data, coeffs, deg):
    for x,y in data:
        plt.scatter(x,y,color='blue')
    x = np.linspace(1, 7, num = 100)
    y = sum(coeffs[i] * x**i for i in range(deg + 1))
    plt.plot(x, y, label='Polynomial Regression')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title("Plot of the polynomial regression")
    plt.legend()
    plt.grid("on")
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
    plot(data, coeffs, 3)
    
