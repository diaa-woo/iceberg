import pygame as pg

pg.init()

screen_width = 480
screen_height = 640
screen = pg.display.set_mode((screen_width, screen_height))
pg.display.set_caption('StickMan!')

character = pg.image.load("stickman.png")
character_size = character.get_rect().size
character_width = character_size[0]
character_height = character_size[1]

character_x_pos = (screen_width / 2) - (character_width / 2)
character_y_pos = screen_height - character_height

background = pg.image.load("background_image.png")

# Event Loop
running = True
while running:
      for event in pg.event.get():
            if event.type == pg.QUIT:
                  running = False
      
      screen.blit(background, (0, 0))
      screen.blit(character, (character_x_pos, character_y_pos))
      pg.display.update()

pg.quit()
