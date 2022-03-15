import math


def triangle(a, b, c):
    if a > 0 and b > 0 and c > 0 and (a + b) > c and (a + c) > b and (b + c) > a:
        print('Это Треугольник')
    else:
        print('Это не тркугольник')


def distance(x1, y1, x2, y2):
    return math.sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))


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

        palindrome(str(input()))

    elif key == "4":
        print("№4")

    elif key == "5":
        print("№5")

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

        a = [77, 'abc']
        from_string_to_list("", a)
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
