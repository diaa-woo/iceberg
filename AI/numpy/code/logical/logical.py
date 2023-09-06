import numpy as np

a1 = np.array([
    [1, 2, 3],
    [4, 5, 6]
])

X1 = a1 % 2 == 0
X2 = a1 >= 4

# and
print(np.logical_and(X1, X2))

# or
print(np.logical_or(X1, X2))

# xor
print(np.logical_xor(X1, X2))
