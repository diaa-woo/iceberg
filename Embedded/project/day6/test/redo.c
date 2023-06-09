#include <stdio.h>

int calculate(int a) {
    if(a > 0) return 2 * calculate(a-1);
    else return 1;

}

int main() {
    int a = 0;
    scanf("%d", &a);
    printf("%d", calculate(a));
    return 0;
}