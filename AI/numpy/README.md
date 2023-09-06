# Numpy

## 소개

**강력한 N차원 배열 객체로 범용적 데이터 처리를 위한 다차원 컨테이너**

과학 연산을 위한 파이썬 핵심 라이브러리 중 하나로, 내부 모듈은 C언어로 구현하여 파이썬의 편의성과 C언어의 고성능 연산 능력을 동시에 이루는 강력한 라이브러리이다.

## 표현

벡터부터 텐서에 이르기까지 다양한 방법으로 만드는 다차원 배열을 제공하며, 선형대수 문제를 쉽게 처리할 수 있다.

- 스칼라(*scalar*)
  - 하나의 값; a = 10
- 벡터(*vector*)
  - 순서가 있는 1차원 배열; x = [0,1,2]
  - 순서가 없는 배열은 `집합(set)`
- 행렬(*matrix*)
  - 벡터 m이 n개 존재(m x n)하는 2차원 배열
  - `1 x n` 행(row) 벡터 `[[1 2]]` 와 `m x 1` 열(column) 벡터는 [[1] [2]]는 서로 전치 관계
- 텐서(*Tensor*)
  - 같은 크기의 행렬로 구성된 3차원 이상 배열

## 사용

인기있는 서드파티 라이브러리들이 Numpy를 기본 자료구조로 사용하거나 호환됨

- matplotlib
- pandas
- opencv
- pytorch
- tensorflow
- etc..

## 하위 문서

- [ndarray](concept/ndarray.md)   
- [배열 생성](concept/create_array.md)   
- [모양 변경](concept/reshape.md)   
- [기본 연산](concept/general_calc.md)   
- [논리 연산](concept/logical.md)   