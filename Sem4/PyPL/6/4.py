class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    '''def __lt__(self, other):
        x_ = self.x < other.x
        y_ = self.y < other.y
        return x_, y_
        return self.x < other.x
        return self.y < other.y'''

    '''def __gt__(self, other):
        return self.x > other.x
        return self.y > other.y'''

    def __eq__(self, other):
        x_ = self.x == other.x
        y_ = self.y == other.y
        return x_ and y_
        # return self.y is other.y

    def __ne__(self, other):
        return not self == other
        # return self.y is not other.y


p1 = Point(1, 2)
p2 = Point(5, 6)

if p1 == p2:
    print("Equal True")
else:
    print("Equal False")

if p1 != p2:
    print("Not equal True")
else:
    print("Not equal False")

p3 = Point(0, 0)
p4 = Point(0, 0)

if p3 == p4:
    print("Equal True")
else:
    print("Equal False")

if p3 != p4:
    print("Not equal True")
else:
    print("Not equal False")

p5 = Point(0, 10)
p6 = Point(0, 0)

if p5 == p6:
    print("Equal True")
else:
    print("Equal False")

if p5 != p6:
    print("Not equal True")
else:
    print("Not equal False")
