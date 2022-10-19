# -*- coding: utf-8 -*-
from pandas import Series, DataFrame
import pandas as pd

import numpy as np

data = [["Вжик", "Zipper the Fly", "fly", "0.7"],
["Гайка", "Gadget Hackwrench", "mouse", None],
["Дейл", "Dale", "chipmunk", "1"],
["Рокфор", "Monterey Jack", "mouse", "0.8"],
["Чип", "Chip", "chipmunk", "0.2"]]

df = DataFrame(data, columns = ['ru_name', 'en_name', 'class', 'cheer'])
df.cheer = df['cheer'].astype('float64')
print(df.dtypes)
print(df)
print(df.count(axis='columns'))
print(df.cheer.count())
print(df.en_name[3])

df1 = df[2: 5: 1]
print(df1)