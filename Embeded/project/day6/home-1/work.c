#include <stdio.h>
#include <stdlib.h>
#include "work.h"

int check(char *p) {
    for(int i = 0; p[i] != '\0'; i++) {
        if(p[i]=='.') return 0;
    }
    return 1;
}

int main() {
    char *p = malloc(sizeof(char) * 10);
    scanf("%s", p);
    int a = check(p);
    if(a==0) {
        float flo = atof(p);
        change_float(flo);
        change_int(change_num_binary);
    }
    else {
        int flo = atoi(p);
        change_int(flo);
    }
    free(p);
    return 0;
}