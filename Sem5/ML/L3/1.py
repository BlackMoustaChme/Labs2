# -*- coding: utf-8 -*-
from pandas import Series, DataFrame
import pandas as pd

import numpy as np

obj2 = Series([1, 2, 3, 4, 5], index=['a', 'b', 'c', 'd', 'e'])

#print(obj2, '\n')
#print(obj2.values)
#print(obj2.index)

#print(obj2['d'], "  ", obj2['b'])

a = pd.Series([6, 7])
print(obj2.append(a))

print(obj2[2: 5: 1])

lis = [[1, 2], [5, 3], [3.7, 4.8]]
frame = DataFrame()
frame['col1'] = lis
frame['col2'] = lis
print(frame)


 