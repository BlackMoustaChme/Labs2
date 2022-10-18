# -*- coding: utf-8 -*-
#https://embeddedinventor.com/pythons-notation-explained-with-examples/
class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None
        
    def __str__(self):
        return '['+self.data+']'

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
        
        
    #def __str__(self):

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
        temp = Node(item)
        while current!= None:
            current = current.getNext()
            
        current.setNext(temp)
            
    def index(self, item):
        current = self.head
        found = False
        index = 0
        
        while current!= None and not found:
            if current.getData() != item:
                index +=1
                current = current.getNext()
            else:
                found = True
                
            if found:
                return index
            else:
                return "Not Found"
    
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
        
    def pop(self):
        current = self.head
        previous = None
        
        if current == None:
            return "No item in list"
        
        while current.getNext() != None:
            previous = current
            current = current.getNext()
        
        previous.setNext(None)
        return current.getData()
    
    def point_pop(self, pos):
        current = self.head
        previous = None
        index = 0
    
        if current == None:
            return "No item in list"
    
        while index < pos and current != None:
            previous = current
            current = current.getNext()
            index += 1
      
        if current == None:
            return "No item in list"
        else:
            if previous == None:
                self.head = current.getNext()
            else:
                previous.setNext(current.getNext())
            return current.getData()
        
    def slice(self, start, stop):
        destination_list = UnorderedList()
        
        


mylist = UnorderedList()

mylist.add(31)
mylist.add(77)
mylist.add(17)
mylist.add(93)
mylist.add(26)
mylist.add(54)

print(mylist.size())
print(mylist.search(93))
print(mylist.search(100))

mylist.add(100)
print(mylist.search(100))
print(mylist.size())

mylist.remove(54)
print(mylist.size())
mylist.remove(93)
print(mylist.size())
mylist.remove(31)
print(mylist.size())
print(mylist.search(93))

