# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import timeit

#1
def foo(i):
   digits = "0123456789"
   if i == 0:
       return "0"
   result = ""
   while i > 0:
       result = digits[i % 10] + result
       i = i // 10
   return result


x=np.arange(1000000, 10000001, 1000000)
x1 = np.arange(1,100)
#x1 = []
y1 = []
y2 = []
y3 = []
inlist = timeit.Timer("i in lis", globals=globals())
inset = timeit.Timer("i in se", globals=globals())

plt.figure()

dellist = timeit.Timer("del lis[0]", globals=globals())
deldict = timeit.Timer("del dic[i-1]", globals=globals())

for i in range(1, 100):
    number = 10 ** i
    #x1.append(number)
    y3.append(timeit.timeit(f'foo({number})', number=10, globals=globals()))
"""#4
for i in range(1000000, 10000001, 1000000):
   lis = list(range(i))
   dl = dellist.timeit(number=1)
   y1.append(dl)

   dic = {a: a for a in range(i)}
   dd = deldict.timeit(number=1)
   y2.append(dd)
"""   
"""#5
   for i in range(1000000, 10000001, 1000000):
   lis = list(range(i))
   il = inlist.timeit(number=1)
   y1.append(il)
   
   se = set(range(i))
   ise = inset.timeit(number=1)
   y2.append(ise)
   
   #plt.plot(i,il)
   #plt.plot(i, ise)
   #print("%15.5f, %15.5f" % (il, ise))"""
#plt.plot(x, y1)
#plt.plot(x, y2)
plt.plot(x1, y3)

plt.show()