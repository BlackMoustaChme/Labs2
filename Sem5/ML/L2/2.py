import numpy as np

# 1
print("1)")
arr_1 = np.array([0, 10, 20, 40, 60])
arr_2 = np.array([10, 30, 40])
res = np.intersect1d(arr_1, arr_2)
print(res)

# 2
print("#2")
arr = np.array([10, 10, 20, 20, 30, 30])
res = np.unique(arr)
print(res)

# 3
print("#3")
arr = np.array([10, 10, 20, 10, 20, 20, 20, 30, 30, 50, 40, 40])
uniq, count = np.unique(arr, return_counts=True)
print(uniq, count)


# 4
print("#4")
arr_5 = np.array([1, 2, 3, 4])
a = []
a = np.append(a, arr_5)
a = np.append(a, arr_5)
a = np.append(a, arr_5)
print(a)

# 5
print("#5")
arr = np.array([200, 300, np.nan, np.nan, np.nan, 700])
res = arr[np.isfinite(arr)]
print(res)

# 6
print("#6")
k = 4
arr = np.array([1, 7, 8, 2, 0.1, 3, 15, 2.5])
res = np.sort(arr)
print(res[:4])

# 7
print("#7")
arr = np.array([0.5, 1.8, 2.1, 3.5, 4.87, 5.13, 6.49])
num = 3.09066280756759
index = (np.abs(arr - num).argmin())
print(arr[index])

# 8
print("#8")
arr1 = np.char.array(["Python", "PHP"])
arr2 = np.char.array(["Java", "C++"])
res = arr1 + " " + arr2
print(res)

# 9
print("#9")
arr = np.char.array(["Python", "PHP", "JS", "examples", "html"])
count = np.char.count(arr, "P")
print(count)

# 10
print("#10")
coeff1 = [1, -4, 7]
coeff2 = [1, -11, 9, 11, -10]
print(np.roots(coeff1))
print(np.roots(coeff2))







