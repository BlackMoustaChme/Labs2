from pandas import Series, DataFrame
import pandas as pd
import matplotlib.pyplot as plt

import numpy as np

data = [["Вжик", "Zipper the Fly", "fly", "0.7"],
["Гайка", "Gadget Hackwrench", "mouse", None],
["Дейл", "Dale", "chipmunk", "1"],
["Рокфор", "Monterey Jack", "mouse", "0.8"],
["Чип", "Chip", "chipmunk", "0.2"]]

print("№1, №6")
df = DataFrame(data, columns = ['ru_name', 'en_name', 'class', 'cheer'])
df.cheer = df['cheer'].astype('float64')
print(df.dtypes)
print(df)

print(" ")

print("№2")
print(df.count(axis='columns'))

print(" ")

print("№3")
print(df.cheer.count())

print(" ")

print("№4")
print(df.en_name[3])

print(" ")

print("№5")
df1 = df.iloc[2:5, [0, 1, 2]]
print(df1)

print(" ")

print("№7")
value = np.log(df['cheer'])
df.insert(4, 'logcheer', value)
print(df)

print(" ")

print("№8")
y = df['class'].value_counts().sort_values()
x =df['class'].unique()
print(y)
print(x)
plt.bar(x, y)
plt.title(
    "Class dataframe column barplot")
plt.xlabel("Class names")
plt.ylabel("Quantity")
plt.show()