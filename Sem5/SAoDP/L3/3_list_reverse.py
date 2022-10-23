from UnorderedList import UnorderedList


def iterative_list_reverse(list: UnorderedList):
    previous = None
    current = list.head
    next = current.getNext()
    while next != None:
        current.setNext(previous)
        previous = current
        current = next
        next = next.getNext()
    current.setNext(previous)
    list.head = current
    return current


# def recursive_list_reverse(list: UnorderedList):


mylist = UnorderedList()
mylist.append(31)
mylist.append(77)
mylist.append(17)
mylist.append(93)
mylist.append(26)
mylist.append(54)
print(mylist)
iterative_list_reverse(mylist)
print(mylist)
# recursive_list_reverse(mylist)
# print(mylist)
