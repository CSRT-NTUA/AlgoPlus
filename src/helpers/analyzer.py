import matplotlib.pyplot as plt
import json
import numpy as np

if __name__ == "__main__":
    with open("info.json", 'r') as input_file:
        file = json.load(input_file)

    input_size = file['input_size']
    exec_time = file['execution_time']

    xx = []
    yy = []
    for x in input_size:
        xx.append(x)

    for y in exec_time:
        yy.append(y)

    plt.scatter(yy, xx, color="red")
    plt.plot(yy, xx)
    plt.grid(1)
    plt.xlabel("Execution time")
    plt.ylabel("Input size")
    plt.title(f"Predicted time complexity of your function is O(N)")
    plt.show()
