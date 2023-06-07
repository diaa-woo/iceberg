import numpy as np

show = lambda m, o : print(m, o.shape, o.dtype, '\n', o, "\n")     # 메크로 설정

a1 = np.array([2, 3, 4], dtype=np.int8)
a2 = np.array((1,5,7,9,10))
a3 = np.array([[2,3,4], [7,9,10]])

show("a1:", a1)
show("a2:", a2)
show("a3:", a3)
