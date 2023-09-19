import pygame as pg

pg.init()

screen_width = 480
screen_height = 640
screen = pg.display.set_mode((screen_width, screen_height))

pg.display.set_caption("Test Game")

# 이미지 로드
background = pg.image.load("background_image.png")

# 이벤트 루프
running = True
while running:
      for event in pg.event.get():
            if event.type == pg.QUIT:
                  running = False
      
      screen.blit(background, (0,0))      # 배경에 이미지를 그려주고 위치 지정
      pg.display.update()

pg.quit()