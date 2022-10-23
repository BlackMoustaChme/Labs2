# https://embeddedinventor.com/pythons-notation-explained-with-examples/
class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None

    # def __str__(self):
    #     return '[' + self.data + ']'

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext


class UnorderedList:

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

    def append(self, item):
        current = self.head
        if current == None:
            self.add(item)
            return
        while current.getNext() != None:
            current = current.getNext()
        temp = Node(item)
        temp.setNext(None)
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


    def slice(self, start, stop):
        if start < 0 or stop < 0 or start > self.size() or stop > self.size():
            raise ("Index out of range")
        current = self.head
        result_list = UnorderedList()
        for _ in range(start):
            current = current.getNext()
        for _ in range(start, stop):
            result_list.append(current.getData())
            current = current.getNext()
        if result_list.size() == 1:
            return result_list.head.data
        return result_list

    def __getitem__(self, item):
        if isinstance(item, slice):
            return self.slice(item.start, item.stop)

if __name__ == "__main__":
    mylist = UnorderedList()
    mylist.append(31)
    mylist.append(77)
    mylist.append(17)
    mylist.append(93)
    mylist.append(26)
    mylist.append(54)
    print(mylist)
    print(mylist.index(17))
    mylist.insert(1, 88)
    print(mylist)
    mylist.pop()
    print(mylist)
    mylist.pop(3)
    print(mylist)
    print(mylist.slice(2, 4))
