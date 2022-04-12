import math

def factorials(n):
    result = 1
    for n_i in range(n):
        result *= n_i + 1
        yield result


def square_fibonacci(n):
    n_k = 0
    n_j = 1
    yield n_j
    for n_i in range(n - 1):
        result = n_k + n_j
        yield result ** 2
        n_k = n_j
        n_j = result

def alphabet():
    i = ord('А') - 1
    while(i != ord('Я')):
        i += 1
        yield chr(i)

def arithmetic_operation(operation):
    if operation == '+':
        return lambda a, b: a + b
    elif operation == '-':
        return lambda a, b: a - b
    elif operation == '*':
        return lambda a, b: a * b
    elif operation == '/':
        return lambda a, b: a / b

def same_by(characteristic, objects):
    return len(set(map(characteristic, objects))) == 1 if objects else True

def print_operation_table(operation, num_rows = 9, num_columns = 9):
    for i in range(1, num_rows + 1):
        answer = []
        for j in range(1, num_columns + 1):
            answer.append(str(operation(i, j)))
        print(''.join(f'{a:<4}' for a in answer))

def check_password(func):
    flag = True
    def wrapper(n):
        nonlocal flag
        if flag:
            if input('Пароль: ') != 'fido':
                print("В доступе отказано")
                return None
            else:
                flag = False
                return func(n)
    return wrapper

@check_password
def fibonacci(n):
    n_k = 0
    n_j = 1
    yield n_j
    for n_i in range(n - 1):
        result = n_k + n_j
        yield result
        n_k = n_j
        n_j = result


def cached(func):
    ch = {}

    def wrapper(*args, **kwargs):
        nonlocal ch
        print(ch)
        if not ch.get(args):
            g = func(*args, **kwargs)
            ch[args] = g
            return g
        else:
            return ch[args]

    return wrapper

@cached
def fib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

print("Список заданий ")
print("Строки", "№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ", "№ 5 ")
print("Списки", "№ 6 ", "№ 7 ", "№ 8 ", "№ 9 ", "№ 10 ")
print("Списки", "№ 11 ", "№ 12 ", "№ 13 ", "№ 14 ", "№ 15 ")
print("Списки", "№ 16 ", "№ 17 ", "№ 18 ", "№ 19 ", "№ 20 ")
print('Введите "0" для выхода из программы')

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")
        list_ = [int(i) for i in input().split()]
        list_under_5 = list(filter(lambda list_under_5: list_under_5 < 5, list_))
        print(list_under_5)
        print(list(x for x in list_ if x < 5))

    elif key == "2":
        print("№2")

        list_ = [int(i) for i in input().split()]
        list_div_2 = list(map(lambda list_div_2: list_div_2 / 2, list_))
        print(list_div_2)
        print(list(x / 2 for x in list_))

    elif key == "3":
        print("№3")

        list_ = [int(i) for i in input().split()]
        print((sum(map(lambda list_pow2: list_pow2 ** 2, filter(lambda list_divs_9: list_divs_9 % 9 == 0, filter(lambda list_above_9: list_above_9 > 9, filter(lambda list_under_100: list_under_100 < 100, list_)))))))
        print(sum(list(x ** 2 for x in list_ if x % 9 == 0 and x > 9 and x < 100)))

    elif key == "4":
        print("№4")

        list_ = [int(i) for i in input().split()]
        condition_list = list(
            map(lambda list_div2: list_div2 / 2, filter(lambda list_above_17: list_above_17 > 17, list_)))
        print(condition_list)
        print(list(x / 2 for x in list_ if x > 17))

    elif key == "5":
        print("№5")
        print(list(factorials(int(input()))))


    elif key == "6":
        print("№6")
        print(list(square_fibonacci(int(input()))))

    elif key == "7":
        print("№7")
        print(list(alphabet()))

    elif key == "8":
        print("№8")
        gen = (chr(i) for i in range(ord('А'), ord('Я') + 1))
        print(list(gen))

    elif key == "9":
        print("№9")
        operation = arithmetic_operation(input())
        print(operation(int(input()), int(input())))

    elif key == "10":
        print("№10")
        list_ = [int(i) for i in input().split()]
        print(same_by(lambda x: x % 2, list_))

    elif key == "11":
        print("№11")
        print_operation_table(lambda x, y: x * y)
        print(" ")
        print_operation_table(lambda x, y: x * y, 5)

    elif key == "12":
        print("№12")
        list_ = input().split()
        list_.sort(key=lambda x: x.lower())
        print(*list_)

    elif key == "13":
        print("№13")
        list_ = [int(i) for i in input().split()]
        list_.sort(key=abs, reverse=True)
        print(*list_)

    elif key == "14":
        print("№14")
        list_ = [[22, 1], [0, 1], [1, 0], [3, 8], [2, 7], [2, -7], [9, 6], [6, 9]]
        list_.sort(key=lambda l: (l[0] ** 2 + l[1] ** 2) ** 0.5)
        print(*list_)

    elif key == "15":
        print("№15")
        t = '''\
        64 33 79 56 78 70 45 71 82 3
        96 27 8 36 72 14 91 10 21 65
        95 28 91 23 78 38 21 50 64 37
        97 54 94 6 48 17 37 19 78 58
        69 58 35 1 70 24 60 17 3 11
        48 9 13 23 82 49 79 55 29 53
        9 2 67 90 0 17 34 55 49 63
        98 98 23 71 66 57 15 94 34 81
        58 37 32 29 10 19 53 46 95 19
        41 24 95 47 58 17 74 69 62 4'''

        print(any(not all(map(int, x.split())) for x in t.split('\n')))

    elif key == "16":
        print("№16")

    elif key == "17":
        print("№17")
        list_ = [[4, 9, 2], [3, 5, 7], [8, 1, 6]]

        res = sum(list_[0])

        if all([sum(x) == res for x in list_]) and all([sum(x) == res for x in list(zip(*list_))]):
            print('YES')
        else:
            print('NO')

    elif key == "18":
        print("№18")
        print(list(fibonacci(int(input()))))

    elif key == "19":
        print("№19")

    elif key == "20":
        print("№20")
        print(fib(int(input())))

    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")
