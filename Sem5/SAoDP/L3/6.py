# -*- coding: utf-8 -*-
#https://stackoverflow.com/questions/42099571/using-a-stack-to-validate-html-script
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


def parChecker(symbolString):
    s = Stack()
    balanced = True
    index = 0
    while index < len(symbolString) and balanced:
        symbol = symbolString[index]
        if symbol in "<":
            s.push(symbol)
        else:
            if s.isEmpty():
                balanced = False
            else:
                top = s.pop()
                if not matches(top, symbol):
                    balanced = False
        index = index + 1
    if balanced and s.isEmpty():
        return True
    else:
        return False


def matches(open, close):
    opens = "<>"
    closers = ">"
    return opens.index(open) == closers.index(close)

def htmlChecker(html):
    htmlStack = Stack()
    
    htmlOpen = ['<html>','<head>','<title>','<body>',\
                '<p>','<b>','<u>','<div>','<span>']
    
    htmlClose =  ['</html>','</head>','</title>','</body>',\
                 '</p>','</b>','</u>','</div>','</span>']
    
    htmlList = html.split()
'''ver1'''

    if len(htmlList) % 2:
        return False
    for v in htmlList:
        if v in htmlOpen:
            htmlStack.push(v)
        else:
            if htmlStack.isEmpty():
                return False
            else:
                v2 = htmlStack.pop()
                if v.replace('/', '') != v2:
                    return False
    return True
    
'''ver1'''