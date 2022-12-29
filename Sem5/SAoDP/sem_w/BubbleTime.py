import random as rand
import numpy as np
import timeit
import timeit
import matplotlib.pyplot as plt


def create_arr_rand(n):
    arr_rand = np.random.randint(1, n, size=n)
    return arr_rand


def create_arr_sort(n):
    arr_sort = np.arange(0, n)
    return arr_sort


def create_arr_binary(n):
    arr_binary = np.array([0] * n)
    for i in range(int(n / 2), n):
        arr_binary[i] = 1
    return arr_binary


def create_arr_insort_plus(n):
    arr_insort_plus = np.arange(n, 0, -1)
    arr_insort_plus[0], arr_insort_plus[int(n / 2)] = arr_insort_plus[int(n / 2)], arr_insort_plus[0]
    return arr_insort_plus


def create_arr_almost_sort(n):
    arr_almost_sort = np.arange(0, n)
    five_percent = int(n * 0.05)
    rand_positions = np.random.randint(1, n, size=five_percent)
    for i in rand_positions:
        # rand = rand.randint(1, n)
        arr_almost_sort[i] = rand.randint(1, n)
    return arr_almost_sort


def bubbleSort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n - 1):
        for j in range(0, n - 1):

            # traverse the array from 0 to n-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def bubbleSortWithModification(arr):
    left_indx = 0  # позиция начала массива
    right_indx = len(arr) - 1  # позиция конца массива
    while True:
        swapped = False  # флаг события обмена
        for i in range(left_indx, right_indx):  # топим тяжёлые элементы
            if arr[i] > arr[i + 1]:
                swapped = True
                arr[i], arr[i + 1] = arr[i + 1], arr[i]

        right_indx -= 1  # сдвиг правой границы влево
        if left_indx < right_indx and swapped:  # если границы не сомкнулись и были события обмена, то продолжаем
            swapped = False
            for j in range(right_indx, left_indx, -1):  # выталкиваем лёгкие элементы
                if arr[j] < arr[j - 1]:
                    swapped = True
                    arr[j], arr[j - 1] = arr[j - 1], arr[j]

            left_indx += 1  # сдвиг левой границы вправо
            if left_indx == right_indx and not swapped:  # провверка на смыкание и отсутствие события перестановки
                return
        else:
            return  # если первое условие не выполнено то массив отсортирован


# def time_check(array):
#     print(" -- Bubble-sort without mods -- ")
#     start_time = timeit.default_timer()
#     bubbleSort(array)
#     print('time =', timeit.default_timer() - start_time)
#
#     print(" -- Bubble-sort with mods -- ")
#     start_time = timeit.default_timer()
#     bubbleSortWithModification(array)
#     print('time =', timeit.default_timer() - start_time)
#     print(" ")
#
#
# def time_check2(arr_1, arr_2, arr_3, arr_4, arr_5):
#     print("Array type: random")
#     time_check(arr_1)
#     print("Array type: sorted")
#     time_check(arr_2)
#     print("Array type: insorted_plus")
#     time_check(arr_3)
#     print("Array type: binary")
#     time_check(arr_4)
#     print("Array type: almost_sorted")
#     time_check(arr_5)
#     print(" ")
#
#
# print("n =")
# n = int(input())
# time_check2(create_arr_rand(n),
#             create_arr_sort(n),
#             create_arr_insort_plus(n),
#             create_arr_binary(n),
#             create_arr_almost_sort(n))

# arr1 = create_arr_almost_sort(n)
# arr2 = create_arr_almost_sort(n)
# print(arr1)
# print(arr2)
# bubbleSort(arr1)
# bubbleSortWithModification(arr2)
# print(arr1)
# print(arr2)

lenghts = [100, 500, 1000, 2000, 4000, 6000, 8000, 10000]
# 2000, 4000, 6000, 8000, 10000
time_rand = [[], []]
time_sort = [[], []]
time_insort_plus = [[], []]
time_binary = [[], []]
time_almost_sort = [[], []]
for i in lenghts:
    random = create_arr_rand(i)
    sorted = create_arr_sort(i)
    insorted_plus = create_arr_insort_plus(i)
    binary = create_arr_binary(i)
    almost_sorted = create_arr_almost_sort(i)

    # time_rand[0].append(timeit.timeit(
    #     "bubbleSort(random)", number=1, globals=globals()))
    # time_rand[1].append(timeit.timeit(
    #     "bubbleSortWithModification(random)", number=1, globals=globals()))
    #
    # time_sort[0].append(timeit.timeit(
    #     "bubbleSort(sorted)", number=1, globals=globals()))
    # time_sort[1].append(timeit.timeit(
    #     "bubbleSortWithModification(sorted)", number=1, globals=globals()))
    #
    # time_insort_plus[0].append(timeit.timeit(
    #     "bubbleSort(insorted_plus)", number=1, globals=globals()))
    # time_insort_plus[1].append(timeit.timeit(
    #     "bubbleSortWithModification(insorted_plus)", number=1, globals=globals()))

    time_binary[0].append(timeit.timeit(
        "bubbleSort(binary)", number=1, globals=globals()))
    time_binary[1].append(timeit.timeit(
        "bubbleSortWithModification(binary)", number=1, globals=globals()))

    time_almost_sort[0].append(timeit.timeit(
        "bubbleSort(almost_sorted)", number=1, globals=globals()))
    time_almost_sort[1].append(timeit.timeit(
        "bubbleSortWithModification(almost_sorted)", number=1, globals=globals()))

# plt.subplot(3, 1, 1)
# plt.plot(lenghts, time_rand[0], label="bubbleSort")
# plt.plot(lenghts, time_rand[1], label="bubbleSortWithModification")
# plt.xlabel("lenght")
# plt.ylabel("time")
# plt.title("Random list")
# plt.legend()
# plt.subplot(3, 1, 2)
# plt.plot(lenghts, time_sort[0], label="bubbleSort")
# plt.plot(lenghts, time_sort[1], label="bubbleSortWithModification")
# plt.xlabel("lenght")
# plt.ylabel("time")
# plt.title("Sorted list")
# plt.legend()
# plt.subplot(3, 1, 3)
# plt.plot(lenghts, time_insort_plus[0], label="bubbleSort")
# plt.plot(lenghts, time_insort_plus[1], label="bubbleSortWithModification")
# plt.xlabel("lenght")
# plt.ylabel("time")
# plt.title("Insorted_plus list")
# plt.legend()
# plt.savefig('Lists123.png', format='png')
plt.subplot(3, 1, 1)
plt.plot(lenghts, time_binary[0], label="bubbleSort")
plt.plot(lenghts, time_binary[1], label="bubbleSortWithModification")
plt.xlabel("lenght")
plt.ylabel("time")
plt.title("Binary list")
plt.legend()
plt.subplot(3, 1, 2)
plt.plot(lenghts, time_almost_sort[0], label="bubbleSort")
plt.plot(lenghts, time_almost_sort[1], label="bubbleSortWithModification")
plt.xlabel("lenght")
plt.ylabel("time")
plt.title("Almost sorted list")
plt.legend()
plt.savefig('Lists45.png', format='png')

plt.subplots_adjust(hspace=1)
plt.show()
plt.close()
