/*
    int a = 1;
    int b = 1;
    *(&a+1) =  10;

    printf("a = %d, b = %d", a, b);
*/

#include <stdio.h>

int main() 
{
    uint32_t score; 
    int total = 0;
    score = 98 << 16 | 68 << 8 | 59;  //한 변수 안에 8비트씩 값을 집어넣어줌
    for(int i = 0; i < 3; i++) {
        total += (score >> 8 * i) & 0xFF;  //0xFF : 1111 1111
    }
    score = score & 0xFF00FF;
    score = score | (86 << 8); 
}