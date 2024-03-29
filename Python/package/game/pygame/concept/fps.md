[상위 문서로 이동](../README.md)

# FPS

FPS는 Frame Per Second의 약자로 주사율, 즉 초당 몇 번의 이미지를 나타내어 주는지에 대한 척도이다.

FPS를 10으로 설정하면 초당 10번의 화면을 출력한다는 의미이고, 해당 값이 높을수록 화면에 부드럽게 출력이 되지만 Computing 자원을 많이 사용하므로 너무 높은 FPS 설정은 하지 않는 것을 권장한다. 주로 10, 30, 60을 사용한다.

FPS의 설정은 `pygame.time.Clock()` 을 변수에 넣고 해당 변수의 메소드로 **`.tick()`** 을 사용한다.

`clock.tick(60)`으로 설정을 하게 되면 1초당 60프레임을 화면에 보여주는 것이다.숫자가 커질수록 캐릭터의 모션이 부드럽게 출력이 된다.

```py
#FPS 설정
clock = pygame.time.Clock()

#이벤트 루프
running = True #게임 진행 여부에 대한 변수 True : 게임 진행 중
while running:
    dt = clock.tick(60) #초당 프레임 수 fps 설정
    for event in pygame.event.get(): #이벤트의 발생 여부에 따른 반복문
        if event.type == pygame.QUIT: #창을 닫는 이벤트 발생했는가?
            running = False
```

여기서 문제가 하나 발생하는게, **캐릭터의 속도와는 별개로 fps 값에 따라 캐릭터의 이동거리가 달라지게 된다.**

예를 들자면, 10 fps일때는 1초에 10번 동작을 해 1번 동작해야 할 때 이동해야 할 거리/10 만큼 움직여야 한다.

그런데 50fps라면? 1번 동작해야 할 때 움직여야할 거리가 달라진다. 즉 같은 동작 수에도 이동 거리가 달라지는 것이다!

왜 이게 문제일까? 서로 다른 컴퓨터 환경 속에서 프레임 수에 따라 캐릭터의 이동속도가 달라진다면 형평성이 떨어진다.

어떻게 해결해줘야 할까? 바로 **프레임이 달라졌을 때 캐릭터의 1번 클릭했을 때 이동거리를 바꿔주면 된다.**

아래와 같이 캐릭터가 이동하는 거리에 프레임 수를 곱해주면 되는데, 아까 `clock.tick()`의 리턴값을 받은 함수 `dt`를 곱해주면 끝이다.

```py
character_x_pos += to_x * dt
character_y_pos += to_y * dt
```