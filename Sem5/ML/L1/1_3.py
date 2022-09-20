# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
 

fig = plt.figure()
plt.plot([10, 20, 30], [20, 40, 10], color='blue', linewidth=1, linestyle=':',label='line1 - dotted')
plt.plot([10, 20, 30],[40, 10, 30], color='red', linewidth=2, linestyle='--' ,label='line2 - dashed')
plt.title('Plot with two or more lines with different styles')
plt.ylabel('y - axis')
plt.xlabel('x - axis')
plt.legend()

plt.savefig('ML1_3.png', format='png')

plt.show()


