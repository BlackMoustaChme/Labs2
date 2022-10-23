from UnorderedList import UnorderedList

def move_to_front(n: int):
    result_list = UnorderedList()
    for _ in range(n):
        line = input()
        if(result_list.search(line)):
            result_list.remove(line)
            result_list.add(line)
        else:
            result_list.add(line)
    print(result_list)


move_to_front(5)