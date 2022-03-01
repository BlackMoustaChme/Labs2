print("Список заданий: ")
print("Множества", "№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ", "№ 5 ")
print('Введите "0" для выхода из программы')

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")

        print("Ввдите список числе(без пробелов):")
        print(len(set(input())))

    elif key == "2":
        print("№2")

        print("Ввдите список числе(с пробелами):")
        print(len(set(input().split()) & set(input().split())))

    elif key == "3":
        print("№3")

        print("Ввдите список числе(с пробелами):")
        print(*sorted(set(input().split()) & set(input().split()), key=int))

    elif key == "4":
        print("№4")

        numbers = [int(i) for i in input().split()]
        before = set()
        for number in numbers:
            print(number, end=' ')
            if number in before:
                print('YES')
            else:
                print('NO')
                before.add(number)

    elif key == "5":
        print("№5")

        words = set()
        for i in range(int(input())):
            words.update(input().split())
        print(len(words))

    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")

