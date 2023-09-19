import pygame

pygame.init()     # 초기화

# 화면 크기 설정
screen_width = 480      # 가로 크기
screen_height = 640     # 세로 크기
screen = pygame.display.set_mode((screen_width, screen_height))

# 화면 타이틀 설정
pygame.display.set_caption("HwanE Game")

# 이벤트 루프
running = True    # 게임 진행 여부에 대한 변수
while running : 
      for event in pygame.event.get():          # 이벤트의 발생 여부에 따른 반복문
            if event.type == pygame.QUIT:       # 창을 닫는 이벤트 발생했는가?
                  running = False

# pygame 종료
pygame.quit()


