import numpy as np

show = lambda m, o : print(m, o.shape, o.dtype, '\n', o, '\n')

a1 = np.array([10, 20, 30, 40, 50, 60])
a2 = np.linspace(5, 6, a1.size)

b1 = a1 - a2
b2 = np.power(b1, 2)    # b1 ** [2, 2, 2, 2, 2, 2]
b3 = np.sin(a1) * 10    # np.sin(a1) * [10, 10, 10, 10, 10, 10]
b4 = a1 % a2
b5 = b1 <25             # b1 < [25, 25, 25, 25, 25, 25]

show("a1:", a1); show("a2:", a2)
show("b1:", b1); show("b2:", b2); show("b3:", b3); show("b4", b4); show("b5:", b5)