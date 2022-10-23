import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

print("№1")
df = pd.read_csv("polit.csv")
df = df.dropna()

print(" ")

print("№2")
print(df[df["fh09"] > 5])

print(" ")

print("№3")
print(df[(df["fparl08"] > 30) & (df["afri"] == 1)])

print(" ")

print("№4")
print(df[((df["afri"] == 1) | (df["lati"] == 1)) & (df["polity09"] >= 8)])

print(" ")

print("№5")
df["corr_round"] = df["corr0509"].apply(lambda x: round(x, 2))
print(df)

print(" ")

print("№6")
fh_statuses = {
    "Free": [1, 2.75],
    "Partly Free": [2.75, 5.25],
    "Not Free": [5.25, 7]
}

def check_status(x):
    for st, rng in fh_statuses.items():
        if rng[0] < x <= rng[1]:
            return st
        
df["fh_status"] = df["fh09"].apply(check_status)
print(df["fh_status"][:5])

print(" ")

print("№7")
v = df.groupby(["fh_status"])
print(v.min()['gini'])
print(v.mean()['gini'])
print(v.max()['gini'])

print(" ")

print("№8")
for name, status in v:
    status.to_csv(f"{name}.csv")
print(" ")

