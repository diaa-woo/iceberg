[상위 문서로 이동](../README.md)

# Surface

pygame에서 surface란 모든 2D객체들을 의미하며(스크린, 배경 이미지, 게임 캐릭터 등), 색이나 이미지를 가지는 빈 시트를 의미한다.

## 생성

```py
# pygame.Surface((width, height))

size = (32, 32)
empty_surface = pygame.Surface(size)
```

## Blitting (블릿팅)

특정 Surface의 픽셀값들을 다른 Surface로 복사하는 것을 말한다. 여러 Surface들을 다른 surface에 디스플레이하기 위해서 필요하다.

### Surface blitting

```py
# 스크린 사이즈 설정
size = (640, 480)
# 스크린 불러오기
screen = pygame.display.set_mode(size)
# 위치 설정
p_pos = (x, y) = (20, 30)
# 이미지 로드
img = pygame.image.load("image.png").convert()

# 불러온 이미지를 설정한 위치에 blit
screen.blit(penguin_img, p_pos)
# blit된 것을 디스플레이 시키기
pygame.display.flit()
```

## 주요 메소드

### blit method

```py
#src surface를 pos에 그리기
blit(src, pos)
#src surface들을 pos에 그리기
blit((src, pos), (src, pos), ...)
```

### fill method

```py
# 지정된 색(r,g,b)으로 색 채우기
fill((r,g,b))
```

### convert() 메서드

Display Surface와 동일한 픽셀 형식의 Surface 복사본을 반환해주는 메서드

```py
# 투명하지 않은 부분을 가지고 있는 이미지 Convert
pygame.image.load(image_path).convert()
# 투명한 부분을 가지고 있는 이미지 convert 시키기
pygame.image.load(image_path).convert_alpha()
```

### get_rect 메서드

```py
# Surface 영역에 대한 rect 객체 반환 - 기준점 죄표(좌측상단), 폭, 높이
get_rect()
```

### get_size 메서드

```py
# Surface의 (폭, 넓이) 반환 -> 튜플 형태로!
get_size()
```

## 출처
https://velog.io/@aza425/pygame.Surface-%EB%AA%A8%EB%93%88