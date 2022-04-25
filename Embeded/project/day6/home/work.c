#include <stdio.h>
#include <stdlib.h>

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
        printf("%f\n",flo);
        change_float(flo);
    }
    else {
        int flo = atoi(p);
        change_int(flo);
    }
    free(p);
    return 0;
}