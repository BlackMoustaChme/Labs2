from UnorderedList import UnorderedList


class Deque:
    def __init__(self):
        self.items = UnorderedList()

    def isEmpty(self):
        return self.items.isEmpty()

    def size(self):
        return self.items.size()

    def __str__(self):
        current = self.items.head
        output = "["
        while current != None:
            output += str(current.getData()) + ", "
            current = current.getNext()
        output = output[:-2] + "]"
        return output

    def addFront(self, item):
        self.items.append(item)

    def addRear(self, item):
        self.items.add(item)

    def removeFront(self):
        return self.items.pop()

    def removeRear(self):
        return self.items.pop(0)



deq = Deque()
deq.addRear(8)
deq.addRear("you")
deq.addFront("they")
print(deq)
print(deq.removeFront())
print(deq)
print(deq.removeRear())
print(deq)