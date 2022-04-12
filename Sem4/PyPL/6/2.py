class Balance:
    def __init__(self):
        self.weight_right = 0
        self.weight_left = 0

    def add_right(self, weight):
        self.weight_right += weight

    def add_left(self, weight):
        self.weight_left += weight

    def result(self):
        if self.weight_right == self.weight_left:
            return "="
        elif self.weight_right > self.weight_left:
            return "R"
        elif self.weight_left > self.weight_right:
            return "L"


balance = Balance()
balance.add_right(10)
balance.add_left(9)
balance.add_left(2)
print(balance.result())
second_balance = Balance()
second_balance.add_right(10)
second_balance.add_left(5)
second_balance.add_left(5)
print(second_balance.result())
second_balance.add_right(1)
print(second_balance.result())
