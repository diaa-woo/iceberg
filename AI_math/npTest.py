import numpy as np
from scipy import linalg as la

s = np.array([3,3*(3)**(1/2)])

print(la.norm(s))

# 단위벡터
s_u = s/la.norm(s)

print(s_u)

def N(vector:list):
    answer = 0
    for i in vector:
        answer += i**2
    return(answer**(1/2))

v1 = np.array([1,-3])
v2 = np.array([-6,-8])
v3 = np.array([-5,-4])
print((la.norm(v1), la.norm(v2), la.norm(v3)))
print(N([1, -3]), N([-6,-8]), N([-5,-4]))

print(v1+v2)
print(v1*4)
print(v1*v2)