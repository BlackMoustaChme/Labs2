class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None
        self.prev = None

    # def __str__(self):
    #     return '[' + self.data + ']'

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def getPrev(self):
        return self.prev

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext

    def setPrev(self, newprev):
        self.prev = newprev


class DoubleList:

    def __init__(self):
        self.head = None

    def __str__(self):
        current = self.head
        output = "["
        while current != None:
            output += str(current.getData()) + ", "
            current = current.getNext()
        output = output[:-2] + "]"
        return output

    def isEmpty(self):
        return self.head == None

    def add(self, item):
        temp = Node(item)
        temp.setNext(self.head)
        temp.setPrev(None)
        self.head = temp

    def size(self):
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.getNext()

        return count

    def search(self, item):
        current = self.head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()

        return found

    def remove(self, item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()

        if previous == None:
            self.head = current.getNext()
        else:
            previous.setNext(current.getNext())
        if current.getNext():
            current.getNext().setPrev(previous)

    def append(self, item):
        current = self.head
        if current == None:
            self.add(item)
            return
        while current.getNext() != None:
            current = current.getNext()
        temp = Node(item)
        temp.setNext(None)
        temp.setPrev(current)
        current.setNext(temp)

    def index(self, item):
        current = self.head
        index = 0
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                index += 1
                current = current.getNext()
        if not found:
            index = None
        return index

    def insert(self, pos, item):
        current = self.head
        previous = None
        index = 0
        temp = Node(item)

        while current != None and index < pos:
            previous = current
            current = current.getNext()
            index += 1

        if pos == 0:
            temp.setNext(self.head)
            self.head = temp
        else:
            if current == None:
                previous.setNext(temp)
            else:
                temp.setNext(current)
                previous.setNext(temp)

    def pop(self, pos=None):
        if self.isEmpty():
            raise ("List is empty")
        current = self.head
        if pos == None:
            while current.getNext() != None:
                current = current.getNext()
        else:
            if self.size() - 1 < pos or pos < 0:
                raise ("Index out of range")
            for _ in range(pos):
                current = current.getNext()
        self.remove(current.getData())
        return current.getData()

    def insert_after(self, pos, item):
        if self.size() - 1 < pos or pos < 0:
            raise ("Index out of range")
        current = self.head
        for _ in range(pos):
            current = current.getNext()
        temp = Node(item)
        temp.setNext(current.getNext())
        temp.setPrev(current)
        if current.getNext():
            current.getNext().setPrev(temp)
        current.setNext(temp)

    def insert_before(self, pos, item):
        if self.size() - 1 < pos or pos < 0:
            raise ("Index out of range")
        current = self.head
        for _ in range(pos):
            current = current.getNext()
        temp = Node(item)
        temp.setNext(current)
        temp.setPrev(current.getPrev())
        if current.getPrev():
            current.getPrev().setNext(temp)
        current.setPrev(temp)
        if temp.getPrev() == None:
            self.head = temp


myDLlist = DoubleList()
myDLlist.append(0)
myDLlist.append(1)
myDLlist.append(2)
myDLlist.append(3)
myDLlist.append(4)
print(myDLlist)
myDLlist.insert_before(3, 10)
myDLlist.insert_after(0, 10)
print(myDLlist)