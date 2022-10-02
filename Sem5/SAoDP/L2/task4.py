import turtle


def koch_curve(size, n, t):
    if n == 0:
        t.forward(size)
    else:
        koch_curve(size / 3, n - 1, t)
        t.left(60)
        koch_curve(size / 3, n - 1, t)
        t.right(120)
        koch_curve(size / 3, n - 1, t)
        t.left(60)
        koch_curve(size / 3, n - 1, t)


def draw_koch_snowflake(size, n, t):
    for i in range(3):
        koch_curve(size, n, t)
        t.right(120)


def main():
    n = int(input())
    t = turtle.Turtle()
    width = 2
    myWin = turtle.Screen()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    # t.left(90)
    # t.up()
    # t.forward(50)
    # t.down()
    # t.right(180)
    t.pensize(width)
    myWin.colormode(255)
    t.pencolor(0, 255, 255)
    t.speed(0)
    draw_koch_snowflake(300, n, t)
    myWin.exitonclick()


main()
