import timeit

dellist = timeit.Timer("del lis[0]", globals=globals())
deldict = timeit.Timer("del dic[i-1]", globals=globals())

print("list     dict")
for i in range(1000000, 10000001, 1000000):
   lis = list(range(i))
   dl = dellist.timeit(number=1)

   dic = {a: a for a in range(i)}
   dd = deldict.timeit(number=1)

   print("%15.5f, %15.5f" % (dl, dd))

#print(dic)