# 도형 그리기

터틀에 내장되어 있는 함수를 이용하여 위와 같이 다양한 도형을 그릴 수 있다.

위의 도형들처럼 그리기 위해서 `circle()`이라는 함수가 필요하다. 이걸로 삼각형 및 사각형도 그릴 수 있다.

## 원 그리기

코드
```Python
import turtle

turtle.setup(width=1000, height=300)
t = turtle.Turtle()

t.penup()
t.goto(-400,0)
t.color("red")
t.pendown()
t.circle(50)  # 반지름 50짜리 원 그리기
```