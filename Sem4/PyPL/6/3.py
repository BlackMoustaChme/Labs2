import math


class Selector:
    def __init__(self, list_):
        self.list_ = list_

    def get_odds(self):
        return list(filter(lambda list_odds: list_odds % 2 != 0, self.list_))

    def get_evens(self):
        return list(filter(lambda list_odds: list_odds % 2 == 0, self.list_))


values = [11, 12, 13, 14, 15, 16, 22, 44, 66]
selector = Selector(values)
odds = selector.get_odds()
evens = selector.get_evens()
print(' '.join(map(str, odds)))
print(' '.join(map(str, evens)))
values_second = [6, 6, 0, 4, 8, 7, 6, 4, 7, 5]
selector = Selector(values_second)
odds = selector.get_odds()
evens = selector.get_evens()
print(' '.join(map(str, odds)))
print(' '.join(map(str, evens)))
values_third = []
selector = Selector(values_third)
odds = selector.get_odds()
evens = selector.get_evens()
print(' '.join(map(str, odds)))
print(' '.join(map(str, evens)))
