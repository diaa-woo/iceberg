[상위 문서로 이동](../README.md)

# Basic

pygame의 가장 기초적인 부분들과 기본적인 기능들을 다루는 문서이다.

## pygame 모듈 설치 및 환경 설정

우선 모듈을 사용하기 전 모듈을 설치해주어야 한다. 간단하게 `pip` 명령어로 pygame을 설치해주면 끝.

```sh
pip install pygame
```

만일 vscode를 사용하는 환경이라면 `pygame snippers`를 설치하면 좋다.

## pygame의 기본 구조

pygame의 기본 구조는 대부분 아래를 따른다.

1. pygame을 사용하기 위해 **import** 해준다.
2. `pygame.init()`으로 pygame 초기화
3. pygame에서 사용할 size, screen, clock 등의 **변수 선언**
4. pygame 메인 루프문 안에 **이벤트, 화면, 사용자 행위 등 설정**

## 단계별로 적용

### import 및 초기화

pygame 라이브러리를 초기화하지 않을 경우에 일부 기능이 정상 작동하지 않을 수 있다.

```py
import pygame

pygame.init()     # 초기화!
```

### 게임 디스플레이 및 타이틀 설정(초기화)

관리하기 쉽게 변수로 창의 크기를 지정해줄 수 있다! 예를 들어 480x640으로 지정해보자.

`pygame.display.set_mode((x,y))` 를 호출하여 화면 크기를 설정하여 창을 생성하는데, (x, y) 튜플 형태로 (가로크기, 세로크기)를 전달한다.

그리고 해당 창이 생성되었을 때의 창의 이름인 *caption*을 달아주는데 `pygame.display.set_caption("")`을 사용해 타이틀을 설정해준다.

```py
# 화면 크기 설정
screen_width = 480      # 가로 크기
screen_height = 640     # 세로 크기
screen = pygame.display.set_mode((screeen_width, screen_height))

# 화면 타이틀 설정
pygame.display.set_caption("HwanE Game")
```

보통 `display`를 통해서 사용자에게 표시될 게임 환경을 설정해줄 수 있는듯 하다.

### pygame 메인 루프 설정

메인 루프에는 해당 게임을 실행하는 동안의 발생한 이벤트에 대한 설정과 게임에 적용되는 알고리즘 부분들이 작성되어야 한다. 예를 들어 사용자가 키를 입력하거나 마우스를 움직이거나 하는 이벤트들을 지속적으로 감시하는 *'이벤트 루프'*를 설정해줘야 한다.

`pygame.event.get()` 함수를 사용해 발생하는 이벤트들을 계속적으로 체크를 해줄 것이다. 게임이 진행되는 동안(`running == True`)에 이벤트가 발생하면 for 구문에서 처리를 해주는 것이다.

여러 이벤트가 발생할 수가 있는데, 그 중 이벤트가 `QUIT`라면 `running`에 `False`를 설정하고 게임을 종료한다. `QUIT 이벤트`는 GUI 창 오른쪽 위에 *[X] 버튼을 누르면 발생하는 이벤트* 이다.

`pygame.QUIT` 이벤트가 발생하면, 반복문을 빠져나와 `pygame.quit()`를 만나 게임이 종료된다.

```py
# Event Loop
running = True    # 게임 진행 여부에 대한 변수
while running:
      for event in pygame.event.get():    # 이벤트의 발생 여부에 따른 반복문
            if event.type == pygame.QUIT:       # 창을 닫는 이벤트가 발생했는가?
                  running = False

# pygame 종료
pygame.quit()
```

위 코드만 실행시켜주면 아무것도 없는 무미건조한 GUI창을 만들어줄 수 있다.

### 배경화면을 만들고 적용해보기

우선 픽셀에 맞는 사진이 있다면 해당 사진을 적용해도 되지만, 마땅히 없으믄 그림판으로 만들어주면 된다. Windows는 그림판을, Ubuntu는 KolourPaint를 사용하면 되지 싶다.

만들어준 이미지를 적용시켜볼 것인데, 변수를 지정해주고 `pygame.image.load()` 를 사용해 이미지 경로를 주어 해당 이미지를 업로드할 것이다.

그리고 해당 이미지를 우리가 만들어 놓은 프레임 배경에 이미지를 그려줘야 하는데, 이는 `screen.blit()`을 사용해주면 된다.

해당 함수에 매개변수 2개를 전달하는데, 처음은 load한 이미지, 두 번째 매개변수는 튜플 형식으로 해당 이미지를 그려줄 위치를 나타내어준다. 그리고 매 프레임마다 화면을 새로 그려주는 동작을 해야 배경이 보인다고 한다.   
이는 `pygame.display.update()`를 사용하여 전체 surface를 업데이트 해준다.

```py
# 배경 이미지 불러오기
background = pygame.image.load("./image.png")

# 이벤트 루프
running = True    # 게임 진행 여부에 대한 변수 
while running:
      for event in pygame.event.get():
            if event.type = pygame.QUIT:
                  running = False
      
      screen.blit(background, (0, 0))
      pygame.display.update()
```

#### 배경을 색깔로만 채워보기

이미지 대신 `screen.fill((RGB값 넣기))` 를 사용하면 아래와 같이 단색으로 배경을 채울 수 있다.

```py
background = pygame.image.load("C:/Users/A/Desktop/PythonWorkSpace/pygame_basic/background.png")

#이벤트 루프
running = True #게임 진행 여부에 대한 변수 True : 게임 진행 중
while running:
    for event in pygame.event.get(): #이벤트의 발생 여부에 따른 반복문
        if event.type == pygame.QUIT: #창을 닫는 이벤트 발생했는가?
            running = False

    screen.fill((7, 77, 17))
    #screen.blit(background, (0, 0)) #배경에 이미지 그려주고 위치 지정
    pygame.display.update()
```

### 캐릭터 만들고 적용하기

character 변수를 지정한 후에 이미지를 불러왔듯이 `pygame.image.load()` 를 사용해 캐릭터 이미지를 가지고 온다.

이미지를 로드하고 캐릭터에 움직임을 부여해주기 전에 해줘야 할 작업들이 있다. 우선 캐릭터의 사이즈를 알아야 한다. 

`character = pygame.image.load("파일 경로")`   
`character_size = character.get_rect().size` 를 사용해 캐릭터의 사이즈를 가지고 온다.

가져온 사이즈의 리스트 첫 번째는 가로 크기, 두 번째는 세로 크기의 값이 들어있다. ([0],[1])

아래와 같이 `character_x_pos`, `character_y_pos`를 두어 캐릭터가 처음에 어느 위치에 있을지를 정해준다. 해당 변수는 캐릭터의 움직임을 설정하기 위해 변수로 두는 것이기도 하다.

```py
# 캐릭터 불러오기
character = pygame.image.load("stickman.png")
character_size = character.get_rect().size      # 캐릭터 이미지 사이즈 구하기
character_width = character_size[0]       # 캐릭터 가로 크기
character_height = character_size[1]      # 캐릭터 세로 크기

# 캐릭터의 기준 좌표를 캐릭터의 왼쪽 상단으로 둔다.
character_x_pos = (screen_width / 2) - (character_width / 2)      # 화면 가로 절반의 중간에 위치. 좌우로 움직이는 변수
character_y_pos = screen_height - character_height          # 이미지가 화면 세로의 가장 아래 위치
```

#### 캐릭터 좌표 설정하고 그려주기

이제 캐릭터를 그려주자. `screen.blit(character, (캐릭터가 위치할 x좌표, 캐릭터가 위치할 y좌표))` 를 입력해주면 된다.

```py
screen.blit(character, (character_x_pos, character_y_pos)) #배경에 캐릭터 그려주기
```

캐릭터 좌표 설정하는 계산이 좀 헷갈릴 수 있는데, `pygame` 상에서의 그래프 좌표는 왼쪽 위에서부터 시작한다. 즉 x좌표는 그대로이지만 y좌표는 반대로 가는 개념이다. 따라서 y값이 증가할수록 GUI 상에서 아래쪽으로 이동한다는 개념이다. 이점 상기

사진을 고를 땐 최대한 아래 여백이 없는 사진, 혹은 모델로 구해주는 것이 좋다. 왜냐면 기존의 y좌표값과 혼동이 생길 수 있기 때문!

## 출처
https://parkjh7764.tistory.com/88
