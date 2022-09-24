import turtle


def tree(branchLen, t, width):
    if branchLen > 5:
        t.pensize(width)
        t.forward(branchLen)#движение вперёд на переданную длину ветки
        t.right(20)#поворот на 20 градусов
        tree(branchLen - 15, t, width - 5)#рекурсивный вызов повторяющий первые два действия до истечения длины ветки
        t.left(40)#поворот на 40 градусов после выхода из рекурсии и возвращения на корень ниже при длине < 5
        tree(branchLen - 15, t, width - 5)#повтор алгоритма
        t.right(20)#возвращение в позицию для отхода по корневой ветке
        t.backward(branchLen)#движение назад


def main():
    t = turtle.Turtle()
    width = 25
    myWin = turtle.Screen()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    t.color("green")
    tree(75, t, width)
    myWin.exitonclick()


main()
