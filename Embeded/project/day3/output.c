#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include "output.h"
#include <stdio.h>

void output(calc_data_t cd, float result) {  //output process
    printf("%.2f %c %.2f = %f\n", cd.opd1, cd.op, cd.opd2, result);
}

#endif