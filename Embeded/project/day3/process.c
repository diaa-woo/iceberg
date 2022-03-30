#include "process.h"

float process(calc_data_t cd) {  //process 
    float result;
    switch (cd.op) {
        case '+':
            result = cd.opd1 + cd.opd2;
            break;
        case '-':
            result = cd.opd1 - cd.opd2;
            break;
        case '*':
            result = cd.opd1 * cd.opd2;
            break;
        case '/':
            result = cd.opd1 / cd.opd2;
            break;
    }
    return result;
}