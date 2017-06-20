import numpy as np
import pylab as plt

n = np.linspace(0,2*np.pi,50)
y = np.sin(n)

"""
r -> red line (b = blue, g = green, y = yellow, k = black)
o / p -> points
* -> stars
-- -> dashed
s -> squares
^ -> triangles
: -> dots
"""
plt.plot(n, y, ':')
plt.show(block=True)

