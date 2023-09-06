[상위 문서로 이동](../README.md)

# 논리 연산(True/False) 논리합, 논리곱

`logical_and`, `logical_or`, `logical_not`, `logical_xor`이 존재한다.

기본적으로 True/False로 구성된 결과가 반환되며 배열과 곱하여 원하는 값을 필터링해줄 수 있다.

## 코드

```py
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
```
|x1|||
|---|----|----|
|False|True|False|
|True|False|True|

|x2|||
|---|----|----|
|False|False|False|
|True|True|True|

result:

```
[[False False False]
 [ True False  True]]
[[False  True False]
 [ True  True  True]]
[[False  True False]
 [False  True False]]
```


## 출처

https://m.blog.naver.com/PostView.naver?blogId=wideeyed&logNo=221621793997&proxyReferer=