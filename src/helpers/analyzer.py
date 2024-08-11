import matplotlib.pyplot as plt
import json
from typing import Tuple
import numpy as np

if __name__ == "__main__":
    with open("info.json", 'r') as input_file:
        file = json.load(input_file)

    input_size = file['input_size']
    exec_time = file['execution_time']
    len_input_size = input_size[0]
    starting = exec_time[0]
    ending = exec_time[0]
    for i in range(len(input_size)):
        len_input_size = max(len_input_size, input_size[i])
        if starting == 0.0 and exec_time != 0.0:
            starting = exec_time[i]
        if exec_time[i] != 0.0:
            starting = min(starting, exec_time[i])
            ending = max(ending, exec_time[i])

    print(f"Highest execution time is {ending}, starting form {starting}...")
    print("Creating the graph...")
    xx, yy = [], []
    for i in range(len(input_size)):
        xx.append(input_size[i])
        yy.append(exec_time[i])

    plt.scatter(yy, xx, color="red")
    plt.plot(yy, xx, color="orange")
    plt.grid(1)
    plt.xlabel("Execution time")
    plt.ylabel("Input size")
    plt.title(f"Predicted time complexity of your function is O(N)")
    plt.show()
