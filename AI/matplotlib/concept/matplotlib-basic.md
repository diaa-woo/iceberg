# Matplotlib

Matplotlib는 파이썬 기본 데이터 형식과 Numpy, Pandas 데이터를 알아보기 쉽게 그래프로 시각화할 수 있는 패키지이다. 인공지능 학습을 위해 수집한 데이터를 시각적으로 확인해보고 데이터 분석, 전처리를 쉽게 할 수 있도록 도와줌

설치 `pip3 install matplotlib`

## GUI 환경

Matplotlib는 그래프를 표현하기 위해 GUI 환경을 사용하는데, 이 그래프를 표현하기 위한 공간에 대한 객체가 `Subplot`이고, 하나 이상의 `Subplot`을 Window에 표현하는 객체가 `Figure`이다.

<img src="https://junn.net/wp-content/uploads/2021/02/test.png"> 

PyQT를 이용한 예제이다. Subplot에서는 대표적으로 선형 그래프, 막대그래프, 히스토그램, 산점도를 표현할 수 있다.

## 그래프

그래프에 사용되는 주요 메소드와 클래스는 다음과 같다.

- `plot(list)`: 지점들을 선으로 이은 그래프를 생성