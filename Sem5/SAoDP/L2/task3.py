import turtle
import numpy as np


def tree(branchLen, t):
    if branchLen > 5:
        angle = np.random.randint(15, 45)
        t.forward(branchLen)#движение вперёд на переданную длину ветки
        t.right(angle)#поворот на 20 градусов
        tree(branchLen - 15, t)#рекурсивный вызов повторяющий первые два действия до истечения длины ветки
        t.left(angle*2)#поворот на 40 градусов после выхода из рекурсии и возвращения на корень ниже при длине < 5
        tree(branchLen - 15, t)#повтор алгоритма
        t.right(angle)#возвращение в позицию для отхода по корневой ветке
        t.backward(branchLen)#движение назад


def main():
    t = turtle.Turtle()
    width = 3
    myWin = turtle.Screen()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    t.pensize(width)
    t.color("brown")
    tree(105, t)
    myWin.exitonclick()


main()
