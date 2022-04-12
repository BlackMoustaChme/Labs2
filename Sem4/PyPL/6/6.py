class SparseArray:
    def __init__(self):
        self.arr = {}

    def __getitem__(self, key):
        return self.arr.get(key, 0)

    def __setitem__(self, key, value):
        self.arr[key] = value


def print_elem(array, ind):
    print('arr[{}] = {}'.format(ind, array[ind]))

print('Пример 1')
arr = SparseArray()
arr[1] = 10
arr[8] = 20
for i in range(10):
    print_elem(arr, i)
print('Пример 2')
second_arr = SparseArray()
second_arr[10] = 123
for i in range(8, 13):
    print_elem(second_arr, i)
print('Пример 3')
third_arr = SparseArray()
index = 1000000000
third_arr[index] = 123

print_elem(third_arr, index - 1)
print_elem(third_arr, index)
print_elem(third_arr, index + 1)
