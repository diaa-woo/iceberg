#include <stdio.h>
#include <unistd.h>

int main() {
    int x;
    x = 0;
    
    fork();

    x = 1;
    printf("PID : %ld, x : %d\n", getpid(), x);
    return 0;  
}