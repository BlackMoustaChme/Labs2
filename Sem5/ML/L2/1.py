import numpy as np

arr = np.array([1, 7, 13, 105])
print ("Type of variables: ", arr.dtype)
print ("Size of memory consumption: ", arr.itemsize * len(arr))
np.savetxt('1_1.txt', arr)
arr.tofile('1_1_bin_file')
print("From binary: ",  np.fromfile('1_1_bin_file'))
print("From txt: ",  np.loadtxt('1_1.txt'))

arr = np.zeros(10)
print(arr)

arr = np.ones(10)
print(arr)

arr = np.linspace(5, 5, 10)
print(arr)

arr = np.arange(30, 70, 2)
print(arr)

arr = np.linspace(5, 50, 10)
print(arr)

arr = np.random.randint(1, 100, size=27)
arr.shape = 3, 3, 3
print(arr)

arr = np.random.randint(30, 41, size=12)
arr.shape = 3, 4
print(arr)

