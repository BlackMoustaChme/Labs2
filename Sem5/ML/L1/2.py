# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
from matplotlib.ticker import FormatStrFormatter, AutoMinorLocator
import numpy as np
 
x1 = np.linspace(1, 4, 10)
y1 = lambda x1: np.log(x1)

x2 = np.linspace(0, 4)
y2 = lambda x2: np.sin(x2)+2.5

fig = plt.figure()

plt.plot(x1, y1(x1) , color='blue', marker = 'o', label='Синяя линяя')
plt.plot(x2, y2(x2), color='red', marker= 'o', label='Красная линия')

#plt.scatter(x1, y1(x1), marker='o', s=10, color='grey')

plt.subplot().xaxis.set_minor_locator(AutoMinorLocator())
plt.subplot().xaxis.set_minor_formatter(FormatStrFormatter('%.1f'))
plt.tick_params(axis='both', which='minor', labelcolor='grey', labelsize=6)
plt.xticks([i for i in range(0, 5)])
plt.yticks([i for i in range(0, 5)])

plt.grid(True, linestyle='--', linewidth=1)

plt.title('Элементы изображения')
plt.ylabel('Подпись оси - OY')
plt.xlabel('Подпись оси - OX')
plt.legend()
plt.show()

plt.savefig('ML2.png', format='png')

