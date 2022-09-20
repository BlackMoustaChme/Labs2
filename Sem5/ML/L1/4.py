# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import numpy as np
 
x = np.linspace(-10, 10)
y = lambda x: np.log((x**2+1)*np.exp(-np.abs(x)/10), 1+np.tan(1/1+np.sin(x)**2))

fig = plt.figure()

plt.plot(x, y(x) , color='blue', linewidth=3, label='y(x)')

plt.grid(True)

plt.savefig('ML4.png', format='png')

plt.show()

