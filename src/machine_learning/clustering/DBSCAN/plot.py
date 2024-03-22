import json
import matplotlib.pyplot as plt

# This is just a template, if you want more clusters please fill more colors to the COLORS list
if __name__ == "__main__":
    f = open('info.json')

    file = json.load(f)
    centroids = file['centroids']
    data = file['data']
    noise = file['noise']
    print(centroids)

    COLORS = ["red", "green", "orange", "blue", "black", "brown", "purple"]
    plt.figure()
    x, y = [], []
    x_noise, y_noise = [], []
    for ww in data:
        x.append(ww[0])
        y.append(ww[1])

    for ww in noise:
        x_noise.append(ww[0])
        y_noise.append(ww[1])
    i = 0
    x_centroids, y_centroids, colors = [], [], []
    for ww in centroids:
        x_centroids.append(ww[0][0])
        y_centroids.append(ww[0][1])
        colors.append(COLORS[ww[1]])

    #plt.scatter(x, y, color="b")
    plt.scatter(x_centroids, y_centroids, color=colors)
    plt.scatter(x_noise, y_noise, color="black")
    #plt.scatter(x_centroids, y_centroids, color=colors)
    plt.show()
