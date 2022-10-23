import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

print("№1")
df = pd.read_csv("la-crimes-sample.csv")

print(" ")

print("№2")
print("rows:")
print(len(df.index))
print("cols:")
print(len(df.columns))

print(" ")

print("№3")
df.info()

print(" ")

print("№4")
print(df.nunique())

print(" ")

print("№5")
print(df.isnull().sum())

print(" ")

print("№6")
count_female = (df["Victim Sex"] == "F").value_counts()
count_male = (df["Victim Sex"] == "M").value_counts()
print("female victims:")
print(count_female[0])
print("male victims:")
print(count_male[0])
if count_female[0] > count_male[0]:
    print("true")
else:
    print("false")

print(" ")

print("№7")
crimes = df["Crime Code"].value_counts()
print(crimes[:10])
crimes_index = list(map(str, crimes[:10].index))
crimes_values = crimes[:10].values
plt.bar(crimes_index, crimes_values)
plt.xlabel("crime code")
plt.ylabel("offense count")
plt.savefig('crimes.png', format='png')

print(" ")

print("№8")
counts_female = df[df["Victim Sex"] == "F"]["Crime Code"].value_counts()
counts_male = df[df["Victim Sex"] == "M"]["Crime Code"].value_counts()
print("female: ", df[df["Crime Code"] == counts_female.index[0]]["Crime Code Description"].values[0])
print("male: ", df[df["Crime Code"] == counts_male.index[0]]["Crime Code Description"].values[0])

print(" ")

print("№9")
print(df["Victim Descent"].value_counts()[:3])

print(" ")

print("№10")
areas = df["Area Name"].value_counts()
safe_n, safe_v = areas.index[-1], areas.values[-1]
dang_n, dang_v = areas.index[0], areas.values[0]
plt.figure()
plt.bar([safe_n, dang_n], [safe_v, dang_v])
plt.savefig('regions.png', format='png')