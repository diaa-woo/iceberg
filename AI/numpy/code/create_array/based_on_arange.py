import numpy as np

show = lambda m, o: print(m, o.shape, o.dtype, '\n', o, '\n')

a1 = np.arange(27+1)
a2 = np.arange(1, 10+1, 0.5)
a3 = np.linspace(1, 10+1, 20)

show("a1:", a1)
show("a2:", a2)
show("a3:", a3)