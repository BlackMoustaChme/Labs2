import numpy as np
import timeit
import sys
import threading


class recursion_depth:
    def __init__(self, limit):
        self.limit = limit
        self.default_limit = sys.getrecursionlimit()

    def __enter__(self):
        sys.setrecursionlimit(self.limit)

    def __exit__(self, type, value, traceback):
        sys.setrecursionlimit(self.default_limit)


def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]

        greater = [i for i in array[1:] if i > pivot]

        return quicksort(less) + [pivot] + quicksort(greater)  # Часть функции


def selection_sort(array):
    for i in range(0, len(array) - 1):
        minm = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minm]:
                minm = j
        array[i], array[minm] = array[minm], array[i]
    # return array


def time_check(array):
    # threading.stack_size(200000000)
    with recursion_depth(5000):
        print("Quicksort")
        start_time = timeit.default_timer()
        quicksort(array)
        print(timeit.default_timer() - start_time)
        print("Selection sort")
        start_time = timeit.default_timer()
        selection_sort(array)
        print(timeit.default_timer() - start_time)


def time_check2(arr_1, arr_2, arr_3):
    time_check(arr_1)
    print(" ")
    time_check(arr_2)
    print(" ")
    time_check(arr_3)
    print(" ")


arr_rand_1 = np.random.randint(1, 1000, size=500)
arr_sort_1 = np.arange(1, 500)
arr_invsort_1 = np.arange(500, 1, -1)

arr_rand_2 = np.random.randint(1, 1000, size=1000)
arr_sort_2 = np.arange(1, 1000)
arr_invsort_2 = np.arange(1000, 1, -1)

arr_rand_3 = np.random.randint(1, 1000, size=1500)
arr_sort_3 = np.arange(1, 1500)
arr_invsort_3 = np.arange(1500, 1, -1)

print("arr_rands")
time_check2(arr_rand_1, arr_rand_2, arr_rand_3)

print("arr_sorts")
time_check2(arr_sort_1, arr_sort_2, arr_sort_3)

print("arr_invsorts")
time_check2(arr_invsort_1, arr_invsort_2, arr_invsort_3)
