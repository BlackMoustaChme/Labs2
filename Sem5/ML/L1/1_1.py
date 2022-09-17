# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

x=np.arange(0, 55, 1)
y=3*x 

fig = plt.figure()
plt.plot(x, y)
plt.title('Draw a line')
plt.ylabel('y - axis')
plt.xlabel('x - axis')

plt.show()

plt.savefig('ML1_1.png', format='png')