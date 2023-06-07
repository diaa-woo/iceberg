import numpy as np

show = lambda m, o : print(m, o.shape, o.dtype, '\n', o, '\n')

a0 = np.zeros(5)
a1 = np.zeros((5,1), dtype=int)
a2 = np.ones((3,4), dtype=int)
a3 = np.full((2,3), -1)
a4 = np.eye(5, k=1)
a5 = np.diag(a4, k=1)

show("a0: ", a0); show("a1: ", a1); show("a2: ", a2);
show("a3: ", a3); show("a4: ", a4); show("a5: ", a5);