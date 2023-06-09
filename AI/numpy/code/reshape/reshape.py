import numpy as np

show = lambda m, o : print(m, o.shape, o.dtype, '\n', o, '\n')

a1 = np.full((6,3), -1)
a2 = np.reshape(a1, (3,3,2))
a3 = np.arange(1, 10 + 1, 0.5).reshape((5,4))
a4 = np.linspace(1, 10 + 1, 20).reshape((2,5,2))

show("a1: ",a1)
show("a2: ",a2)
show("a3: ",a3)
show("a4: ",a4)