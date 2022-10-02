import numpy as np

# 1
print("#1")
arr = np.array([1, 7, 13, 105])
print("Type of variables: ", arr.dtype)
print("Size of memory consumption: ", arr.itemsize * len(arr))
np.savetxt('1_1.txt', arr)
arr.tofile('1_1_bin_file')
print("From binary: ", np.fromfile('1_1_bin_file'))
print("From txt: ", np.loadtxt('1_1.txt'))

# 2
print("#2")
arr = np.zeros(10)
print(arr)

arr = np.ones(10)
print(arr)

arr = np.linspace(5, 5, 10)
print(arr)

# 3
print("#3")
arr = np.arange(30, 70, 2)
print(arr)

# 4
print("#4")
arr = np.linspace(5, 50, 10)
print(arr)

# 5
print("#5")
arr = np.random.randint(1, 100, size=27)
arr.shape = 3, 3, 3
print(arr)

# 6
print("#6")
arr = np.random.randint(30, 41, size=12)
arr.shape = 3, 4
print(arr)

# 7
print("#7")
arr = np.ones((10, 10))
arr[1:-1, 1:-1] = 0
print(arr)

# 8
print("8)")
arr = np.diag([1, 2, 3, 4, 5])
print(arr)

# 9
print("9)")
arr = np.zeros((4, 4))
arr[::2, 1::2] = 1
arr[1::2, ::2] = 1
print(arr)

# 10
print("10)")
arr = np.arange("2017-03", "2017-04", dtype="datetime64[D]")
print(arr)
