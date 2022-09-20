# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt

langs = ["Java", "Python", "PhP", "JavaScript", "C#", "C++" ] 
scores = [22.2, 17.6, 8.8, 8, 7.7, 6.7]
explode = [0.1, 0, 0, 0, 0, 0.08]

fig = plt.figure()


plt.title(
    "Popularity of Programming Language\n Worldwide, Oct 2017 compared to a year ago",
    bbox={"edgecolor": "black", "facecolor": "grey"})
plt.pie(scores, labels=langs, autopct="%1.1f%%", explode=explode,
        wedgeprops={"ls": "-", "edgecolor": "black"})

plt.savefig('ML5_8.png', format='png')

plt.show()