#include <stdio.h>

int __attribute__((weak)) a = 10;   // weak symbol

int main() {
    printf("a = %d\n", a);
    funcA();
    
    return 0;
}