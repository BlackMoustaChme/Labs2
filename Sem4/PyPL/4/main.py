print("Список заданий ")
print("Строки", "№ 1 ", "№ 2 ", "№ 3 ", "№ 4 ")
print('Введите "0" для выхода из программы')

while True:
    print(" ")
    print("Введите номер задания")
    print("Ввод:")
    key = ''
    key = input(key)
    if key == "1":
        print("№1")

        counter = {}

        for word in input().split():
            counter[word] = counter.get(word, 0) + 1
            print(word, counter[word] - 1)

    elif key == "2":
        print("№2")

        n = int(input())
        synonym = {}

        for i in range(n):
            first, second = input().split()
            synonym[first] = second
            synonym[second] = first

        print(synonym[input()])

    elif key == "3":
        print("№3")

        n = int(input())
        vote = {}

        for i in range(n):
            name, count = input().split()
            vote[name] = vote.get(name, 0) + int(count)

        print()

        for name, count in sorted(vote.items()):
            print(name, count)

    elif key == "4":
        print("№4")

        ACTION = {
            'read': 'R',
            'write': 'W',
            'execute': 'X',
        }

        file_system = {}
        n = int(input())

        for i in range(n):
            file, *actions = input().split()
            file_system[file] = set(actions)

        for i in range(int(input())):
            action, file = input().split()
            if ACTION[action] in file_system[file]:
                print('OK')
            else:
                print('Access denied')

    elif key == "5":
        print("№5")

        from collections import Counter

        words = []
        for _ in range(int(input())):
            words.extend(input().split())

        counter = Counter(words)
        pairs = [(-pair[1], pair[0]) for pair in counter.most_common()]
        words = [pair[1] for pair in sorted(pairs)]

        print()
        print('\n'.join(words))


    elif key == "0":
        print("До Свидания!")
        break

    else:
        print("Такого номера задания нет, попробуйте ещё раз")
