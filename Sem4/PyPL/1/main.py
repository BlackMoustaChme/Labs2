print("№1")
print("1.Введите название фильма")
print("2.Введите название кинотеатра")
print("3.Введите Время сеанса ")
print("Ввод:")
print('Билет на "', input(), '" в "', input(), '" на ', input(), "забронирован")

print("№2")

a = ''
b = ''
a = input(a)
b = input(b)
if a == 'да' and b == 'да' or a == 'нет' and b == 'нет':
    print('"ВЕРНО"')
else:
    print('"НЕВЕРНО"')

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

print("№4")

print(input())

print("№5")

if input() == '':
    print('"ДА"')
else:
    print('"НЕТ"')

print("№6")
