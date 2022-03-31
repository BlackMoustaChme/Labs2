# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
#if __name__ == '__main__':
    #print_hi('PyCharm')
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



    elif key == "6":
        print("№6")


    elif key == "7":
        print("№7")


    elif key == "8":
        print("№8")
        gen = (chr(i) for i in range(ord('А'), ord('Я') + 1))
        print(list(gen))

    elif key == "9":
        print("№9")

    elif key == "10":
        print("№10")


    elif key == "11":
        print("№11")


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


    elif key == "19":
        print("№19")

    elif key == "20":
        print("№20")


    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")

