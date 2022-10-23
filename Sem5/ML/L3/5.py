import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


df = pd.read_csv("vgsales.csv")

print("№1")
print(df["Platform"].unique())

print(" ")

print("№2")
df_metagames = pd.read_csv("metacritic_games.csv")
df_merged = pd.merge(df, df_metagames, on=["name".lower()], how="inner")
print(df_merged)
df["metacritic_rating"] = df_merged["rating"]
print(df)

print(" ")

print("№3")
games_2012 = df[(df["metacritic_rating"] == "M") & (df["Year"] >= 2012)]
print(games_2012)

print(" ")

print("№4")
print(games_2012.describe())

print(" ")

print("№5")
def check_vowels(x):
    vowels = ['a', 'e', 'i', 'o', 'u']
    count = 0
    for v in vowels:
        if v in x:
            count += 1
    if count >= 3:
        return True
    return False
        
genres = df[df["Genre"].apply(check_vowels)]
result = {}
unique_genres = genres["Genre"].unique()
for genre in unique_genres:
    g = genres[genres["Genre"] == genre]
    result[genre] = g['Name'].count()

print(result)


