import numpy as np
from matplotlib import pyplot as plt   
import math
import sympy as sp
from sympy import diff

def sup(xi, x, deff):
    dx = sp.symbols('x')
    dif = diff(deff, dx, n + 1) #n+1 производная
    print("n+1 производная: ", dif)
    el = []
    for i in list(xnew):
        el.append(dif.subs('x',1))
    m = np.max(el)
    return m

def lagrange(x):
    f = 0
    product = 1
    for i in range(len(x)):
        y = np.cos(np.sin(np.cos(x[i])))
        #print(y)
        #print("iteration:", i)
        for j in range(len(x)):
            if j != i:
                polynomial = lambda x: (x - x[j])/(x[i] - x[j])
                #print("polynomial(x):")
                #print(polynomial(x))
                product = product * polynomial(x)
                #print("product:")
                #print(product)
        f = f + (y * product)
        product = 1
        #print("  ")
    return f
              

x_nodes = np.arange(-2, 2, 1)
x_whole = np.arange(-2, 2, 0.1)

y = lambda x_whole: np.cos(np.sin(np.cos(x_whole)))

print(y(x_whole))
print(lagrange(x_whole))
print(lagrange(x_nodes))

#su = sup(x, xnew, y) 
#fact = math.factorial(len(xx)+1)
        
diff_4 = lambda x: -np.sin(x)^4·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))+np.sin(x)^4·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-3·np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))
-np.sin(x)^4·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))·np.cos(np.cos(x))^2-np.sin(x)^4·np.sin(np.cos(x))^2·np.cos(np.sin(np.cos(x)))+np.sin(x)^4·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-3·np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))
-2·np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))-2·np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))-2·np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))+2·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))·np.cos(x)^2
-3·np.sin(x)^4·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))·np.cos(np.cos(x))^2+np.sin(x)^4·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^4-3·np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))^3
-2·np.sin(x)^4·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))·np.cos(np.cos(x))^2-2·np.sin(x)^4·np.sin(np.cos(x))^2·np.cos(np.sin(np.cos(x)))+2·np.sin(x)^4·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-6·np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))
-2·np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))^3-4·np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))+2·np.sin(x)^2·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-2·np.cos(x)^2·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2
-np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))-np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))-np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))+np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))·np.cos(x)^2-np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.sin(np.cos(x))+np.sin(x)^2·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))-np.sin(x)^2·np.sin(np.sin(np.cos(x)))·np.cos(x)·np.cos(np.cos(x))^3-2·np.sin(x)^2·np.sin(np.cos(x))·np.cos(x)·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))+np.sin(x)^2·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2-np.cos(x)^2·np.cos(np.sin(np.cos(x)))·np.cos(np.cos(x))^2


#y_z = y(x)[0]
#x_z = x[0]
#print(y_z)
#print(x_z)

# coefficient = (y(x)[0] / ((x[0] - x[1]) * (x[0] - x[2]) * (x[0] - x[3]))) + (
#             y(x)[1] / ((x[1] - x[0]) * (x[1] - x[2]) * (x[1] - x[3]))) + (
#                           y(x)[2] / ((x[2] - x[0]) * (x[2] - x[1]) * (x[2] - x[3]))) + (
#                           y(x)[3] / ((x[3] - x[0]) * (x[3] - x[1]) * (x[3] - x[2])))


# print(coefficient)

#Lagr_3 = lambda x: (y(x)[0] * ((x - x[1]) * (x - x[2]) * (x - x[3])) / (
#            (x[0] - x[1]) * (x[0] - x[2]) * (x[0] - x[3]))) + (y(x)[1] * ((x - x[0]) * (x - x[2]) * (x - x[3])) / (
#            (x[1] - x[0]) * (x[1] - x[2]) * (x[1] - x[3]))) + (y(x)[2] * ((x - x[0]) * (x - x[1]) * (x - x[3])) / (
#            (x[2] - x[0]) * (x[2] - x[1]) * (x[0] - x[3]))) + (y(x)[3] * ((x - x[0]) * (x - x[1]) * (x - x[2])) / (
#            (x[3] - x[0]) * (x[3] - x[1]) * (x[3] - x[2])))
#print(Lagr_3(x))