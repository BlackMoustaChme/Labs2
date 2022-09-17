import timeit

inlist = timeit.Timer("i in lis", globals=globals())
inset = timeit.Timer("i in se", globals=globals())

print("list     set")
for i in range(1000000, 10000001, 1000000):
   lis = list(range(i))
   il = inlist.timeit(number=1)

   se = set(range(i))
   ise = inset.timeit(number=1)

   print("%15.5f, %15.5f" % (il, ise))

#print(dic)