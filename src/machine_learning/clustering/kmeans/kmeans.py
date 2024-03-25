import json
import matplotlib.pyplot as plt
import os
import random


def fill_data():
    data = []
    for i in range(100):
        x = random.randint(0, 5)
        y = random.randint(0, 5)
        data.append([x, y])

    for i in range(100):
        x = random.randint(90, 100)
        y = random.randint(90, 100)
        data.append([x, y])

    for i in range(100):
        x = random.randint(-10, -5)
        y = random.randint(-10, -5)
        data.append([x, y])

    return data

# This is just a template, if you want more clusters please fill more colors to the COLORS list
if __name__ == "__main__":
    # here you should fill the data
    # parser should be better here(or add an option for parser)
    data = fill_data()
    CLUSTERS = 3
    data_dict = {
            "data":data
            }
    json_object = json.dumps(data_dict)
    
    with open("data.json", "w") as outfile:
        outfile.write(json_object)
    
    # run the kmeans clustering with CLUSTERS clusters
    os.system(f"c++ -std=c++17 kmeans.cc")
    os.system(f"./a.out {CLUSTERS}")
    
    input_name = open("info.json", 'r') 
    file = json.load(input_name)
    centroids = file['centroids']
    assignments = file['assignments']
    COLORS = ["red", "green", "orange", "blue", "black", "brown", "purple"]
    plt.figure()
    x, y = [], []
    x_noise, y_noise = [], []
    for ww in data:
        x.append(ww[0])
        y.append(ww[1])

    i = 0
    x_centroids, y_centroids, colors = [], [], []
    for ww in assignments:
        x_centroids.append(ww[0][0])
        y_centroids.append(ww[0][1])
        colors.append(COLORS[ww[1]])

    #plt.scatter(x, y, color="b")
    plt.scatter(x_centroids, y_centroids, color=colors)
    #plt.scatter(x_noise, y_noise, color="black")
    #plt.scatter(x_centroids, y_centroids, color=colors)
    plt.show()
