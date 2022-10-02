import numpy as np


def solve(num: int):
    coefficient = []
    b = []
    for i in range(num):
        print(f"Введите коэффициенты {i + 1} уравнения и свободный член:")
        entered_data = input().split()
        while (len(entered_data) != num + 1):
            print("Введите данные еще раз")
            entered_data = input().split()
        coefficient.append(list(map(int, entered_data[:-1])))
        b.append(int(entered_data[-1]))

    if np.linalg.det(coefficient) != 0:
        x = np.linalg.solve(coefficient, b)
        return x
    else:
        return "Система не имеет решений (или имеет их бесконечно много)"


x = solve(2)
print(x)
