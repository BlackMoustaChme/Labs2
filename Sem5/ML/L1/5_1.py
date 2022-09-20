# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt

langs = ["Java", "Python", "PhP", "JavaScript", "C#", "C++" ] 
scores = [22.2, 17.6, 8.8, 8, 7.7, 6.7]

fig = plt.figure()

plt.bar(langs, scores, color="blue")
plt.minorticks_on()
plt.grid(True, which="major", color="red")
plt.grid(True, which="minor", linestyle="--")
plt.title("Popularity of Programming Language\n Worldwide, Oct 2017 compared to a year ago")
plt.xlabel("Languages")
plt.ylabel("Popularity")

plt.savefig('ML5_1.png', format='png')

plt.show()



