import numpy as np

A = np.mat([[1,2],[7,6]])
B = np.mat([[4,-1],[6,4]])

#print(np.linalg.inv(A)*np.mat([[2],[-1],[4]]))
print(A*B,'\n',B*A)
