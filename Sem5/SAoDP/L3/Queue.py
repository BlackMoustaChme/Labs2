from UnorderedList import UnorderedList


class Queue:
    def __init__(self):
        self.items = UnorderedList()

    def isEmpty(self):
        return self.items.isEmpty()

    def enqueue(self, item):
        self.items.add(item)

    def dequeue(self):
        return self.items.pop()

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

if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(8)
    queue.enqueue(True)
    queue.enqueue("you")
    queue.dequeue()
    print(queue)