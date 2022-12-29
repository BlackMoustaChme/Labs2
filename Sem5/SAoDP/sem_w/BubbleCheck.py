import numpy as np
import timeit
import sys
import threading

def bubbleSort(arr):
    n = len(arr)
    i_swap = 0
    i_compare = 0
    # optimize code, so if the array is already sorted, it doesn't need
    # to go through the entire process
    # swapped = False
    # Traverse through all array elements
    for i in range(n - 1):
        # range(n) also work but outer loop will
        # repeat one time more than needed.
        # Last i elements are already in place
        for j in range(0, n - 1):

            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j + 1]:
                # swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                i_swap += 1
                print('i_swap =', i_swap)
            i_compare += 1
            print('i_compare =', i_compare)
            print("array condition:")
            print(arr)
        # if not swapped:
        #     # if we haven't needed to make a single swap, we
        #     # can just exit the main loop.
        #     return


arr1 = [7, 3, 9, 4, 2, 5, 6, 1, 8]

arr2 =[3, 5, 2, 9, 8, 1, 6, 4, 7]

# bubbleSort(arr1)
#
# print("Sorted array is:")
# for i in range(len(arr1)):
#     print("% d" % arr1[i], end=" ")

bubbleSort(arr2)

print("Sorted array is:")
for i in range(len(arr2)):
    print("% d" % arr2[i], end=" ")

