class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


s = Stack()

while True:
    expr = input()
    if expr:
        expr = expr.split()
        for sumb in expr:
            if sumb in ("+", "-", "/", "*") and s.size() > 1:
                num1 = int(s.pop())
                num2 = int(s.pop())
                print("Result: ", end="")
                if sumb == "+":
                    num = num1 + num2
                elif sumb == "-":
                    num = num1 - num2
                elif sumb == "*":
                    num = num1 * num2
                elif sumb == "/":
                    num = num1 / num2
                s.push(num)
                print(num)
            elif sumb.isdigit():
                s.push(sumb)
            else:
                print("Invalid operation")
    else:
        break
