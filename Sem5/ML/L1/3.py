# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

x=np.arange(-10, 10, 1)
y=x*x-x-6 
y2=x-x
fig = plt.figure()
plt.plot(x, y, color='blue')
plt.plot(x, y2, color='black')
plt.scatter(3,0, color='red')
plt.scatter(-2,0, color='red')
plt.title('y(x)=x*x-x-6 graph')
plt.ylabel('y - axis')
plt.xlabel('x - axis')

plt.show()

plt.savefig('ML3.png', format='png')