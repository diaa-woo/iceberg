[상위 문서로 이동](../README.md)

# Pygame Event

## 키보드의 키가 눌렸을 때 이벤트

우선 Pygame의 키보드 이벤트 타입에는 무엇이 있는지 알아야 한다. 

아래 이벤트는 대표적인 이벤트 타입이며, 이외에도 상당히 많이 있다.

|이벤트 타입|이벤트 동작|이벤트 속성|
|---------|---------|---------|
|`pygame.QUIT`| 윈도우의 x버튼, 창 닫기 버튼 눌러짐 | none |
|`pygame.ACTIVEEVENT`| 마우스가 화면에 들어가거나 나가면 발생<br><br>gain: 0 - 마우스가 화면에 들어올 때<br>gain: 1 - 마우스가 화면에서 나갔을 때<br><br>state: 1 - 창이 활성화<br>state: 2 - 창이 비활성화<br>state: 6 - 비활성화된 창이 활성활될 때 | gain, state |
|`pygame.KEYDOWN`| 키가 눌렸을 때 | key, mod, unicode, scancode |
|`pygame.KEYUP`| 키가 올라갔을 때 | key, mod |
|`pygame.MOUSEMOTION` | 마우스 움직일 때 | pos, rel, buttons |
|`pygame.MOUSEBUTTONUP` | 마우스 버튼을 뗄 때 | pos, button |
|`pygame.MOUSEBUTTONDOWN` | 마우스 버튼을 눌렀을 때 | pos, button |

이벤트 루프에 `if event.type == pygame.KEYDOWN:` 을 추가해준다. 그리고 키가 눌렀을 때 어떤 키가 눌렸는지를 조건문을 사용해서 표현을 해주는데, 예를 들어 `pygame.K_LEFT`와 같이 **방향키를 눌렀을 때** 캐릭터가 이동할 수 있도록 설정해줄 수 있다.

상술한 `pygame.K_LEFT`는 pygame 모듈의 key 값을 의미하며, 아래와 같은 키 값들을 가지고 있다. 원하는거 가져오면 좋을듯

```
pygame
Constant      ASCII   Description
---------------------------------
K_BACKSPACE   \b      backspace
K_TAB         \t      tab
K_CLEAR               clear
K_RETURN      \r      return
K_PAUSE               pause
K_ESCAPE      ^[      escape
K_SPACE               space
K_EXCLAIM     !       exclaim
K_QUOTEDBL    "       quotedbl
K_HASH        #       hash
K_DOLLAR      $       dollar
K_AMPERSAND   &       ampersand
K_QUOTE               quote
K_LEFTPAREN   (       left parenthesis
K_RIGHTPAREN  )       right parenthesis
K_ASTERISK    *       asterisk
K_PLUS        +       plus sign
K_COMMA       ,       comma
K_MINUS       -       minus sign
K_PERIOD      .       period
K_SLASH       /       forward slash
K_0           0       0
K_1           1       1
K_2           2       2
K_3           3       3
K_4           4       4
K_5           5       5
K_6           6       6
K_7           7       7
K_8           8       8
K_9           9       9
K_COLON       :       colon
K_SEMICOLON   ;       semicolon
K_LESS        <       less-than sign
K_EQUALS      =       equals sign
K_GREATER     >       greater-than sign
K_QUESTION    ?       question mark
K_AT          @       at
K_LEFTBRACKET [       left bracket
K_BACKSLASH   \       backslash
K_RIGHTBRACKET ]      right bracket
K_CARET       ^       caret
K_UNDERSCORE  _       underscore
K_BACKQUOTE   `       grave
K_a           a       a
K_b           b       b
K_c           c       c
K_d           d       d
K_e           e       e
K_f           f       f
K_g           g       g
K_h           h       h
K_i           i       i
K_j           j       j
K_k           k       k
K_l           l       l
K_m           m       m
K_n           n       n
K_o           o       o
K_p           p       p
K_q           q       q
K_r           r       r
K_s           s       s
K_t           t       t
K_u           u       u
K_v           v       v
K_w           w       w
K_x           x       x
K_y           y       y
K_z           z       z
K_DELETE              delete
K_KP0                 keypad 0
K_KP1                 keypad 1
K_KP2                 keypad 2
K_KP3                 keypad 3
K_KP4                 keypad 4
K_KP5                 keypad 5
K_KP6                 keypad 6
K_KP7                 keypad 7
K_KP8                 keypad 8
K_KP9                 keypad 9
K_KP_PERIOD   .       keypad period
K_KP_DIVIDE   /       keypad divide
K_KP_MULTIPLY *       keypad multiply
K_KP_MINUS    -       keypad minus
K_KP_PLUS     +       keypad plus
K_KP_ENTER    \r      keypad enter
K_KP_EQUALS   =       keypad equals
K_UP                  up arrow
K_DOWN                down arrow
K_RIGHT               right arrow
K_LEFT                left arrow
K_INSERT              insert
K_HOME                home
K_END                 end
K_PAGEUP              page up
K_PAGEDOWN            page down
K_F1                  F1
K_F2                  F2
K_F3                  F3
K_F4                  F4
K_F5                  F5
K_F6                  F6
K_F7                  F7
K_F8                  F8
K_F9                  F9
K_F10                 F10
K_F11                 F11
K_F12                 F12
K_F13                 F13
K_F14                 F14
K_F15                 F15
K_NUMLOCK             numlock
K_CAPSLOCK            capslock
K_SCROLLOCK           scrollock
K_RSHIFT              right shift
K_LSHIFT              left shift
K_RCTRL               right control
K_LCTRL               left control
K_RALT                right alt
K_LALT                left alt
K_RMETA               right meta
K_LMETA               left meta
K_LSUPER              left Windows key
K_RSUPER              right Windows key
K_MODE                mode shift
K_HELP                help
K_PRINT               print screen
K_SYSREQ              sysrq
K_BREAK               break
K_MENU                menu
K_POWER               power
K_EURO                Euro
K_AC_BACK             Android back button
```

## 예제 : 키보드 방향키가 눌렸을 때 캐릭터 이동시키기

앞서 작성한 이벤트 루프 코드에서 `pass` 부분에 방향키를 눌렀을 때 캐릭터의 좌표이동을 설정해줄 것이다.

```py
# Event Loop
running = True
while running:
      for event in pygame.event.get():
            if event.type == pygame.QUIT:
                  running = False
            
            if event.type == pygame.KEYDOWN:
                  if event.key == pygame.K_LEFT :
                        pass
                  elif event.key == pygame.K_RIGHT:
                        pass
                  elif event.key == pygame.K_DOWN:
                        pass
  k               elif event.key == pygame.K_UP:
                        pass
                  
```

위의 코드에서 캐릭터 이동 좌표를 `to_x`, `to_y` 변수로 두고 키보드 방향키가 눌림에 따라 캐릭터의 좌표에서 빼거나 더해줄 것이다.

`basic` 문서에서도 적어놨듯이 일반적인 좌표 기분이 다르다. **x좌표 기준으로 오른쪽은 +, 왼쪽은 -** 이고, **y좌표 기준으로 위쪽은 -, 아래쪽은 +** 이다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Ferz5L7%2Fbtru3t55Z93%2FV0hdInAbYmaS9k6V99Xvu1%2Fimg.png">

```py
if event.key == pygame.K_LEFT:
      to_x -= 0.5
```

코드를 보면 왼족 방향키가 눌렸을 때 x좌표를 -0.5만큼 빼서 왼쪽으로 이동시켜줄 것이다.

그런데 위와 같이 코드를 작성하여 캐릭터를 이동시키다 보니 화면 밖으로 나가게 되버린다. 

이때 조건문을 이벤트 루프 안에 설정해주어 캐릭터가 화면 밖으로 나가지 않도록 해주어야 한다.

캐릭터 좌표와 스크린 좌표 값을 비교하여, 해당 값을 벗어났을 때 캐릭터 좌표의 값을 그 값에 머물게 함으로써 넘어가지 못하는 느낌을 줄 수 있다.

```py
# 왼쪽, 오른쪽 경계 설정
      if character_x_pos < 0:
            character_x_pos = 0
      
      elif character_x_pos > screen_width - character_width :
            character_x_pos = screen_width - character_width

      # 위, 아래쪽 경계 설정
      if character_y_pos < 0:
            character_y_pos = 0
      
      elif character_y_pos > screen_height - character_height :
            character_y_pos = screen_height - character_height
```
