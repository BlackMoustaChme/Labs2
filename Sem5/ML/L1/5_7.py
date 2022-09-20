# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt

langs = ["Java", "Python", "PhP", "JavaScript", "C#", "C++" ] 
scores = [22.2, 17.6, 8.8, 8, 7.7, 6.7]
explode = [0.1, 0, 0, 0, 0, 0]

fig = plt.figure()

plt.pie(scores, labels=langs, autopct="%1.1f%%", explode=explode,
        wedgeprops={"ls": "-", "edgecolor": "black"})

plt.savefig('ML5_7.png', format='png')

plt.show()