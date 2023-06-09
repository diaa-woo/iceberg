//uint 이런 자료형을 사용할 경우 다른 플랫폼으로 이동시 재사용성이 높아짐과 동시에 강력한 힘을 발휘할 수 있음!

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define array_size(ar) (sizeof(ar) / sizeof(ar[0]))

#define WIDTH           10
#define HEIGHT          10
#define SCREEN_SIZE     WIDTH*HEIGHT

static uint8_t screen[SCREEN_SIZE];

void display(uint8_t *data)
{
    for(int y = 0; y<SCREEN_SIZE; y++) {
        printf("%c ", data[y]);
        if((y+1) % WIDTH == 0) printf("\n");
    }
}

int main ()
{
    memset(screen, '.', array_size(screen));  //모든 메모리에 .을 집어넣어줌!
    display(screen);

    //todo

    /*uint8_t *p = &screen;
    for(int i = 0; i<SCREEN_SIZE/2; i++) {
        *(p+(i*2)+1) = '*'; 
        *(p+(i*2)) = '.';
    }
    display(screen);*/  //내가 만든거

    uint32_t step = 5;
    uint8_t (*p)[step] = (uint8_t (*)[step])screen;
    for (int pos = 0; pos <SCREEN_SIZE / step; pos++) {
        *p[pos] = '*';
    }
    
    display(screen);
}