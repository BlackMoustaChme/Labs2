class Polynomial:

    def __init__(self, coefficients):
        self.coefficients = coefficients

    def __call__(self, x):
        res = 0
        for i in range(len(self.coefficients)):
            res += pow(x, i) * self.coefficients[i]
        return res

    def __add__(self, other):
        list_ = []
        res = Polynomial(list_)
        if len(self.coefficients) < len(other.coefficients):
            n = len(self.coefficients)
        else:
            n = len(other.coefficients)
        for i in range(n):
            list_.append(self.coefficients[i] + other.coefficients[i])
        if len(self.coefficients) > n:
            list_ += self.coefficients[n::]
        else:
            list_ += other.coefficients[n::]
        res.coefficients = list_
        return res


print('Пример 1')
poly = Polynomial([10, -1])
print(poly(0))
print(poly(1))
print(poly(2))

print('Пример 2')
poly1 = Polynomial([0, 0, 1])
print(poly1(-2))
print(poly1(-1))
print(poly1(0))
print(poly1(1))
print(poly1(2))
print()

poly2 = Polynomial([0, 0, 2])
print(poly2(-2))
print(poly2(-1))
print(poly2(0))
print(poly2(1))
print(poly2(2))
print()

poly3 = poly1 + poly2
print(poly3(-2))
print(poly3(-1))
print(poly3(0))
print(poly3(1))
print(poly3(2))
print()

print('Пример 3')
poly4 = Polynomial([0, 1])
poly5 = Polynomial([10])
poly6 = poly4 + poly5
poly7 = poly5 + poly4

print(poly6(-2), poly7(-2))
print(poly6(-1), poly7(-1))
print(poly6(0), poly7(0))
print(poly6(1), poly7(1))
print(poly6(2), poly7(2))
