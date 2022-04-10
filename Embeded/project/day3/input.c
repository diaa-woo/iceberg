#include "input.h"
#include <stdio.h>

void input(calc_data_t *cd) {  //input process
    scanf("%f %c %f", cd->opd1, cd->op, cd->opd2);  //포인터로 받았기에 역참조 시켜버림!
}