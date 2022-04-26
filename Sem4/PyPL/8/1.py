#
import numpy as np

arr_1 = np.linspace(3, 3, 12).reshape(3, 4)
print(arr_1)
arr_2 = np.random.randint(9, size=(2, 4))
print(arr_2)
print(arr_1.size)
print(arr_2.size)
print(np.row_stack((arr_1, arr_2)))
arr_3 = np.array([1, 8, 6, 5, 8, 3])
print(arr_3)
arr_4 = arr_3 * 3 + 1
print(arr_4)
arr_5 = arr_3.reshape(2, 3)
print(arr_5)
print(arr_5.min(axis=1))
print(arr_5.sum() / arr_5.size)
arr_6 = np.arange(10) ** 2
print(arr_6)
print(arr_6[1::2])
print(arr_6[::-1])
arr_6[1::2] = 2
print(arr_6 == 49)
A = np.array(([-5, 4, 3, 2, -1, 0], [0, 1, -2, -3, 4, 5]))
print(A)
B = A[A < 0]
print(B)
