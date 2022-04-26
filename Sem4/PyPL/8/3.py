#
import numpy as np


def super_sort(rows, cols):
    A = np.random.randint(1, 101, (rows, cols))
    B = A.copy()
    B[:, ::2] = -np.sort(-B[:, ::2], axis=0)
    B[:, 1::2] = np.sort(B[:, 1::2], axis=0)
    return A, B


A, B = super_sort(3, 5)
print('A:\n', A, '\nB:\n', B)