# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.font_manager as fm
import matplotlib.gridspec as gridspec
import matplotlib.pyplot as plt
import os

from matplotlib import rc, rcParams
from matplotlib.ticker import FormatStrFormatter, NullFormatter
from matplotlib.ticker import AutoMinorLocator, FixedLocator, MultipleLocator
from random import randint, choice
from numpy import pi

rcParams['font.family'] = 'fantasy'
rcParams['font.fantasy'] = 'Arial'

def save(name='', fmt='png'):
    pwd = os.getcwd()
    if not os.path.exists('matplot_files'):
        os.mkdir('matplot_files')
    os.chdir('matplot_files')
    iPath = f'{fmt}'
    if not os.path.exists(iPath):
        os.mkdir(iPath)
    os.chdir(iPath)
    plt.savefig(f'{name}.{fmt}', fmt=fmt)
    os.chdir(pwd)
    
x=np.arange(0, 55, 1)
y=3*x 

fig = plt.figure()
plt.plot(x, y)
plt.title('Draw a line')
plt.ylabel('y - axis')
plt.xlabel('x - axis')

save('ML1_1.png', fmt='pdf')

plt.savefig('ML1_1.png', format='png')

plt.show()

#save('ML1_1.png', fmt='pdf')


#plt.savefig('ML1_1.png', format='png')

