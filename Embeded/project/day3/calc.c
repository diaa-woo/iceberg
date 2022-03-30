#include <stdio.h>
#include "input.h"
#include "output.h"
#include "process.h"

int main(void) {
    calc_data_t cp;
    float result;
    
    input(&cp);
    result = process(cp);
    output(cp, result);

    return 0;
}



