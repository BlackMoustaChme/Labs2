import timeit


def foo(i):
   digits = "0123456789"
   if i == 0:
       return "0"
   result = ""
   while i > 0:
       result = digits[i % 10] + result
       i = i // 10
   return result


for i in range(1, 100):
    number = 10 ** i
    print(timeit.timeit(f'foo({number})', number=10, globals=globals()))
