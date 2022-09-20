import timeit
import numpy as np

c = 0
n = int(input())
lis = list(np.random.randint(0, 100, size=n))
for i in range(n):
    for j in range(n-1):
        if lis[i] == lis[j+1]:
            print("1")
            c = c + 1
        else:
            print("0")
if (c>0):
    print("No")
else:
    print("Yes")
checkset = set(lis)
if(len(checkset)==n):
    print("True. All uniques")
else:
    print("False. Not all unique")

