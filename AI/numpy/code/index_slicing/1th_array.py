import numpy as np

show = lambda m, o: print(m, o.shape, o.dtype, '\n', o, '\n')

a1 = np.arange(1, 10+1) ** 2
a2 = a1[2:9]                  # 슬라이싱 저장

show("a1", a1) ; show("a2", a2)

a1[3] = a1[1] + a1[2]
a2[:5:2] = 10_1000            # [0:5:2] : 0~5까지, 2만큼 건너뛰어 10_1000변환 -> 이때 a1도 같이 변함!!!!

for i in range(len(a1)):
      print(a1[(i+1)*-1], end=',')        # 역순 출력
print()