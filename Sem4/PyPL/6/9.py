class Triangle:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def perimeter(self):
        return self.a + self.b + self.c


class EquilateralTriangle(Triangle):
    def __init__(self, a):
        super().__init__(a, a, a)


t = Triangle(3, 4, 5)
print(t.perimeter())
eqt = EquilateralTriangle(2)
print(eqt.perimeter())
