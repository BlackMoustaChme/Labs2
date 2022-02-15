print("Список заданий: ")
print("№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ", "№ 5 ", "№ 6 ")
print("№ 7 ", "№ 8 ", "№ 9 ", "№ 10 ", "№ 11 ", "№ 12", "№ 13")

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")
        print("1.Введите название фильма")
        print("2.Введите название кинотеатра")
        print("3.Введите Время сеанса ")
        print("Ввод:")
        print('Билет на "', input(), '" в "', input(), '" на ', input(), "забронирован")

    elif key == "2":
        print("№2")

        a = ''
        b = ''
        a = input(a)
        b = input(b)
        if a == 'да' and b == 'да' or a == 'нет' and b == 'нет':
            print('"ВЕРНО"')
        else:
            print('"НЕВЕРНО"')

    elif key == "3":
        print("№3")

        print("1.Логин")
        print("2.Резервный адрес")
        print("Ввод:")
        a = 0
        while a == 0:
            if '@' not in input() and '@' in input():
                print('"ВЕРНО"')
                a = 1
            else:
                print('"Ещё раз"')

    elif key == "4":
        print("№4")

        print(input())

    elif key == "5":
        print("№5")

        if input() == '':
            print('"ДА"')
        else:
            print('"НЕТ"')

    elif key == "6":
        print("№6")
        print("Введите трёхзначное число")
        a = 0
        while a == 0:
            number = list(input())
            count = 0
            for i in number:
                count = count + 1
            if count == 3:
                a = 1
            else:
                print("Вы ввели не трёхзначное число")
                print("Введите ТРЁХЗНАЧНОЕ число")
        maxi = max(number)
        mini = min(number)

        for i in number:
            if i != maxi and i != mini:
                break
        if (int(maxi) + int(mini)) / 2 == int(i):
            print("Вы ввели красивое число")
        else:
            print("Жаль, вы ввели обычное число")

    elif key == "7":
        print("№7")

        print("Введите четырёхзначное число")
        number = int(input())
        if number > 999 and number < 10000:

            x1 = number // 1000
            x2 = number // 100 % 10
            x3 = number // 10 % 10
            x4 = number % 10

            if x1 > x2:
                x1, x2 = x2, x1
            if x2 > x3:
                x2, x3 = x3, x2
            if x3 > x4:
                x3, x4 = x4, x3
            if x1 > x2:
                x1, x2 = x2, x1
            if x2 > x3:
                x2, x3 = x3, x2
            if x1 > x2:
                x1, x2 = x2, x1
            if x1 == 0 and x2:
                x1, x2 = x2, x1
            elif x1 == 0 and x3:
                x1, x3 = x3, x1
            elif x1 == 0 and x4:
                x1, x4 = x4, x1

            print(x4 + 10 * (x3 + 10 * (x2 + 10 * x1)))
        else:
            print("Число не четырёхзначное. Попробуйте снова")

    elif key == "8":
        print("№8")

        Max = 150
        Min = 190

        x = input()
        count = 0

        while x != "!":
            z = int(x)
            if z > 150 and z < 190:
                count += 1
                if z > Max:
                    Max = z
                if z < Min:
                    Min = z
            x = input()

        print(count)
        print(Min, Max)

    elif key == "9":
        print("№9")
        a = 0
        while a == 0:
            print("Введите новый пароль: ")
            p1 = ''
            p1 = input(p1)
            print("Введите ещё раз для подтверждения: ")
            p2 = ''
            p2 = input(p2)
            if len(p1) < 8:
                print('"Короткий"')
                print('"Ещё раз"')
            elif '123' in p1:
                print('"Простой"')
                print('"Ещё раз"')

            elif p1 != p2:
                print('"Различаются"')
                print('"Ещё раз"')
            else:
                print('"OK"')
                a = 1

    elif key == "10":
        print("№10")

        x = "start"

        while x != "x":
            number1 = int(input())
            x = input()
            if x == "+":
                print(number1 + int(input()))
            elif x == "-":
                print(number1 - int(input()))
            elif x == "*":
                print(number1 * int(input()))
            elif x == "/":
                number2 = int(input())
                if number2 != 0:
                    print(number1 // number2)
            elif x == "%":
                number2 = int(input())
                if number2 != 0:
                    print(number1 % number2)
            elif x == "!":
                if number1 >= 0:
                    factorial = 1
                    for i in range(2, number1 + 1):
                        factorial *= i
                    print(factorial)
            elif x == "x":
                print(number1)

    elif key == "11":
        print("№11")

        n = int(input())

        for i in range(1, 2 * n, 2):
            empty = " " * ((2 * n - 1 - i) // 2)
            print(empty + "*" * i + empty)

    elif key == "12":
        print("№12")

        print("Введите целое положительное число")
        n = int(input())
        if n > 0:
            number = 1
            limit = 1
            inLine = 0

            while number <= n:
                print(number, end=" ")
                number += 1
                inLine += 1
                if inLine == limit:
                    print()
                    limit += 1
                    inLine = 0
        else:
            print("Число N не удовлетворяет требованиям. Попробуйте снова")

    elif key == "13":
        print("№13")

        print("Введите N и M, параметры прямоугольника")
        n = int(input())
        m = int(input())
        if n > 0 and m > 0:
            symbol = input()

            print(symbol * m)
            for i in range(1, n - 1):
                print(symbol + " " * (m - 2) + symbol)
            print(symbol * m)
        else:
            print("Числа N и M не удовлетворяет требованиям. Попробуйте снова")

    elif key == "0":
        print("До Свидания!")
        break
    else:
        print("Такого номера задания нет, попробуйте ещё раз")
