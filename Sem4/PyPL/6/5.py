class ReversedList:
    def __init__(self, list_):
        self.list_ = list_

    def __len__(self):
        return len(self.list_)

    def __getitem__(self, key):
        return self.list_[-(key + 1)]


rl = ReversedList([10, 20, 30])
for i in range(len(rl)):
    print(rl[i])

second_rl = ReversedList([])
print(len(second_rl))

third_rl = ReversedList([10])
print(len(third_rl))
print(third_rl[0])
