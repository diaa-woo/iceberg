#include <stdio.h>
#include "work.h"

int change_to_decimal(int exponent) {
    if(exponent > 0) return 2 * change_to_decimal(exponent-1);
    else return 1;
}

void change_num(int sign, int exponent, int mantissa) {
    int a;
    if(sign == 0) a = 1;
    else a == -1;
    change_num_binary = a * change_to_decimal(exponent-127) * mantissa;
    printf("%d\n", change_num_binary);
    return;
}