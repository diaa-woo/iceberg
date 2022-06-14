import numpy as np

X1 = np.array([[2, 7], [5, 1]])
X2 = np.array([[1, -1, 0], [3,1,3],[4,1,3]])

v = np.array([-4, 5])
w = np.array([-2, 8])

print(v+w)
print(3*v)

print(np.linalg.matrix_rank(X1)) # 이 함수로 rank를 계산
print(np.linalg.matrix_rank(X2))

X1 = np.array([3, 1, 4])
X2 = np.array([2, 2, -4])
X3 = np.array([-1, -1, 1])

print(np.dot(X1, X2))
print(np.dot(X2, X3))
print(np.dot(X1, X3))

# X1, X2 / X2, X3 이루는 각에 대한 cos값은?

lenX1 = np.linalg.norm(X1)
lenX2 = np.linalg.norm(X2)
lenX3 = np.linalg.norm(X3)

print(np.dot(X1, X2)/(lenX1*lenX2))
print(np.dot(X2, X3)/(lenX2*lenX3))