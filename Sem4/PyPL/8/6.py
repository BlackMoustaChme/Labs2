import numpy as np

with open("F:\Chernousov\labs2\Sem4\PyPL\8\lines", "r", encoding="utf-8") as file:
    lines = file.readlines()
    print(np.random.choice(lines))
