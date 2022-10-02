import timeit


def tribonacci(n):
    if n in (1, 2):
        return 0
    if n in (3,):
        return 1
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)


def tribonacci_ax(n, n2=None, n3=None):
    if n in (1, 2):
        return 0
    if n in (3,):
        return 1

    n3 = n3 or tribonacci_ax(n - 3)
    n2 = n2 or tribonacci_ax(n - 2, n3)

    return tribonacci_ax(n - 1, n2, n3) + n2 + n3


def time_check(n):
    print("tribonacci")

    start_time = timeit.default_timer()
    tribonacci(n)
    print(timeit.default_timer() - start_time)

    print("tribonacci_ax")

    start_time = timeit.default_timer()
    tribonacci_ax(n)
    print(timeit.default_timer() - start_time)


print(time_check(30))
