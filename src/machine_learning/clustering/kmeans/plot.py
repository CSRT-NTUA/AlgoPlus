import json
import matplotlib.pyplot as plt

# This is just a template, if you want more clusters please fill more colors to the COLORS list
if __name__ == "__main__":
    f = open('info.json')

    file = json.load(f)
    keys = file['assignments']
    centroids = file['centroids']
    data = file['data']
    
    COLORS = ["red", "green", "orange", "blue"]
    plt.figure()
    x, y = [], []
    for ww in data:
        x.append(ww[0])
        y.append(ww[1])
    i = 0
    x_centroids, y_centroids, colors = [], [], []
    for ww in keys:
        x_centroids.append(keys[i][0][0])
        y_centroids.append(keys[i][0][1])
        colors.append(COLORS[keys[i][1]])
        i += 1
    plt.scatter(x_centroids, y_centroids, color=colors)
    plt.show()
