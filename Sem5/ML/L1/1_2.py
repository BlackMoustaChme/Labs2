# -*- coding: utf-8 -*-
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
 

#fig = plt.figure()
plt.plot([10, 20, 30], [20, 40, 10], color='blue', linewidth=3, label='line1 - width-3')
plt.plot([10, 20, 30],[40, 10, 30], color='red', linewidth=5, label='line2 - width-5')
plt.title('Two or more lines with different widths and colors with suitable legends')
plt.ylabel('y - axis')
plt.xlabel('x - axis')
plt.legend()
plt.show()

plt.savefig('ML1_2.png', format='png')