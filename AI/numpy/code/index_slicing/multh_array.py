import numpy as np

show = lambda m, o: print(m, o.shape, o.dtype, '\n', o, '\n')

a1 = np.fromfunction(lambda x,y,z : x+y+z, (2,5,4), dtype=int)
a2 = a1[:, 1::2, :3] * 10     # a2는 새로운 배열! : 크기가 다르기에 브로드캐스팅, 즉 사본 복사!

a2[1, ...] = -1

show("a1", a1)
show("a2", a2)
for array in a2:
      print("out:\n", array)

# for element in a2.flat
#     print(element, end=',')