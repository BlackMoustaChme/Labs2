import math


def triangle(a, b, c):
    if a > 0 and b > 0 and c > 0 and (a + b) > c and (a + c) > b and (b + c) > a:
        print('Это Треугольник')
    else:
        print('Это не тркугольник')


def distance(x1, y1, x2, y2):
    return math.sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))


def number_to_words(n):
    n1 = {1: 'один',
          2: 'два',
          3: 'три',
          4: 'четыре',
          5: 'пять',
          6: 'шесть',
          7: 'семь',
          8: 'восемь',
          9: 'девять'}
    n2 = {10: 'десять',
          20: 'двадцать',
          30: 'тридцать',
          40: 'сорок',
          50: 'пятьдесят',
          60: 'шестьдесят',
          70: 'семьдесят',
          80: 'восемьдесят',
          90: 'девяносто'}
    n3 = {11: 'одиннадцать',
          12: 'двенадцать',
          13: 'тринадцать',
          14: 'четырнадцать',
          15: 'пятнадцать',
          16: 'шестнадцать',
          17: 'семнадцать',
          18: 'восемнадцать',
          19: 'девятнадцать'}

    n_1 = n % 10
    n_2 = n - n_1

    if n < 10:
        return n1.get(n)
    elif n < 20 and n > 10:
        return n3.get(n)
    else:
        if n_1 == 0:
            return n2.get(n)
        else:
            return n2.get(n_2) + " " + n1.get(n_1)


def palindrome(s):
    s = s.lower().replace(" ", '')

    if s == s[::-1]:
        print('Палиндром')
    else:
        print('Не Палиндром')


def mirror(arr):
    mirrored_part = []
    mirrored_part += arr
    mirrored_part.reverse()
    arr += mirrored_part


def from_string_to_list(string, container):
    string = string.replace(" ", '')
    container += string


print("Список заданий ")
print("Строки", "№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ", "№ 5 ")
print("Списки", "№ 6 ", "№ 7 ", "№ 8 ", "№ 9 ", "№ 10 ")
print("Списки", "№ 11 ", "№ 12 ", "№ 13 ", "№ 14 ", "№ 15 ")
print('Введите "0" для выхода из программы')

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")

        triangle(int(input()), int(input()), int(input()))

    elif key == "2":
        print("№2")

        print(distance(float(input()), float(input()), float(input()), float(input())))

    elif key == "3":
        print("№3")

        print(number_to_words(int(input())))

    elif key == "4":
        print("№4")

    elif key == "5":
        print("№5")

        palindrome(str(input()))

    elif key == "6":
        print("№6")


    elif key == "7":
        print("№7")


    elif key == "8":
        print("№8")

        arr = [1, 2]
        mirror(arr)
        print(*arr)

    elif key == "9":
        print("№9")

        a = [1, 2, 3]
        from_string_to_list("1 3 99 52", a)
        print(*a)

    elif key == "10":
        print("№10")


    elif key == "11":  #
        print("№11")

    elif key == "12":  #
        print("№12")

    elif key == "13":
        print("№13")


    elif key == "14":
        print("№14")


    elif key == "15":
        print("№15")



    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")
