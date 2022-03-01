print("Список заданий: ")
print("Строки", "№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ")
print("Списки", "№ 5 ", "№ 6 ", "№ 7 ", "№ 8 ", "№ 9 ")
print('Введите "0" для выхода из программы')

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")

        print("Ввдите строку:")
        s = ''
        s = input(str(s))
        print(s[2])
        print(s[-2])
        print(s[:5])
        print(s[:-2])
        print(s[0::2])
        print(s[1::2])
        print(s[::-1])
        print(s[:0:-2])
        print(len(s))

    elif key == "2":
        print("№2")

        print("Ввдите строку:")
        s = ''
        s = input(str(s))
        p1 = (int(len(s) / 2))
        p2 = int(len(s)) - p1
        s1 = s[:p1]
        s2 = s[-p2:]
        s3 = s2 + s1
        print(s3)

    elif key == "3":
        print("№3")

        print('Ввдите строку в которой минимум два раза встречается "h"')
        s = ''
        s = input(str(s))
        p1 = (int(s.find('h')))
        # print(p1)
        p2 = (int(s.rfind('h'))) - 1
        # print(p2)
        print(s[p2:p1:-1])

    elif key == "4":
        print("№4")

        print("Ввдите строку:")
        s = ''
        s = input(s)
        # s.find('f')
        if s.count("f") == 1:
            print(s.find('f'))

        elif s.count('f') > 2:
            print(s.find('f'))
            print(s.rfind('f'))

        elif s.count('f') == 0:
            continue

    elif key == "5":
        print("№5")

        print("Ввдите список (последовательность цифр без пробелов):")

        l = [int(i) for i in input()]

        for i in range(1, len(l)):
            if l[i] > l[i - 1]:
                print(l[i], end=" ")

    elif key == "6":
        print("№6")

        print("Ввдите список (Сначала кол-во элементов, потом элементы по одному через Enter):")

        l = []

        for i in range(int(input())):
            l.append(int(input()))
            # l = [int(i) for i in input()]

        for i in range(1, len(l)):
            if l[i] > 0 and l[i - 1] > 0:
                print(l[i], " ", l[i - 1])
                break
            elif l[i] < 0 and l[i - 1] < 0:
                print(l[i], " ", l[i - 1])
                break

    elif key == "7":
        print("№7")

        print("Ввдите список (последовательность цифр без пробелов):")

        l = [int(i) for i in input()]

        for i in range(0, len(l) - 1, 2):
            l[i], l[i + 1] = l[i + 1], l[i]

        print(l)

    elif key == "8":
        print("№8")

        print("Ввдите список (последовательность цифр без пробелов):")

        l = [int(i) for i in input()]
        print(set(l))

    elif key == "9":
        print("№9")

        print("Ввдите список (Элементы по два через пробел и Enter в конце строки):")

        n = 8
        x = []
        y = []
        correct = True

        for i in range(0, n):
            x_input, y_input = [int(line) for line in input().split()]
            x.append(x_input)
            y.append(y_input)

        for i in range(n):
            for j in range(i + 1, n):
                if x[i] == x[j] or y[i] == y[j] or abs(x[i] - x[j]) == abs(y[i] - y[j]):
                    correct = False

        if correct:
            print('NO')
        else:
            print('YES')

    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")
