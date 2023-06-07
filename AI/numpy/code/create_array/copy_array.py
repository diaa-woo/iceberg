import numpy as np

show = lambda m, o : print(m, o.shape, o.dtype, '\n', o, '\n')

a = np.linspace(1, 12, 12).reshape((2, 3, 2))

b1 = np.ones_like(a)
b2 = np.zeros_like(a)
b3 = np.full_like(a, -1)

show("a:", a)
show("b1: ", b1)
show("b2: ", b2)
show("b3: ", b3)
