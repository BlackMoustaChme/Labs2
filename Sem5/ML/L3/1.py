# -*- coding: utf-8 -*-
from pandas import Series, DataFrame
import pandas as pd

import numpy as np

print("№1")
obj2 = Series([1, 2, 3, 4, 5], index=['a', 'b', 'c', 'd', 'e'])

print(obj2, '\n')
print(obj2.values)
print(obj2.index)

print(" ")

print("№1, №2")
print(obj2['d'], "  ", obj2['b'])

print(" ")

print("№3")
a = pd.Series([6, 7])
print(obj2.append(a))

print(" ")

print("№4")
print(obj2[2: 5: 1])

print(" ")

print("№5")
df = pd.DataFrame([[1, 2], [5, 3], [3.7, 4.8]], columns=['col1', 'col2'])
print(df)

print(" ")

print("№6")
print(df['col1'][2])

print(" ")

print("№7")
df[df == 3] = 9
print(df)

print(" ")

print("№8")
print(df[1:3])

print(" ")

print("№9")
df['col3'] = df['col1'] * df['col2']
print(df)


 