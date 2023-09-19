import pygame as pg

pg.init()

screen_width = 480
screen_height = 640
screen = pg.display.set_mode((screen_width, screen_height))
pg.display.set_caption("stickkman")

# 캐릭터 설정
character = pg.image.load("little_big_stickman.png")
character_size = character.get_rect().size
character_width = character_size[0]
character_height = character_size[1]

character_x_pos = (screen_width / 2) - (character_width / 2)
character_y_pos = screen_height - character_height

background = pg.image.load("background_image.png")

# moving
to_x = 0
to_y = 0

# FPS 설정
clock = pg.time.Clock()

# Event Loop
running = True
while running:
      dt = clock.tick(60)     # 초당 프레임 수 fps 설정
      for event in pg.event.get():
            if event.type == pg.QUIT:
                  running = False
            if event.type == pg.KEYDOWN:
                  if event.key == pg.K_LEFT:
                        to_x -= 0.5
                  if event.key == pg.K_RIGHT:
                        to_x += 0.5
                  if event.key == pg.K_UP:
                        to_y -= 0.5
                  if event.key == pg.K_DOWN:
                        to_y += 0.5

            if event.type == pg.KEYUP:
                  if event.key == pg.K_LEFT or event.key == pg.K_RIGHT:
                        to_x = 0
                  if event.key == pg.K_UP or event.key == pg.K_DOWN:
                        to_y = 0

      character_x_pos += to_x * dt
      character_y_pos += to_y * dt

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
      
      screen.blit(background, (0,0))
      screen.blit(character, (character_x_pos, character_y_pos))
      pg.display.update()

pg.quit()