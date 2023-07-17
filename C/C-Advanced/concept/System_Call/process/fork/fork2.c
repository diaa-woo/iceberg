#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    pid_t pid;

    int x;
    x = 0;

    pid = fork();

    if(pid > 0) {
        x = 1;
        printf("부모 PID : %ld, x : %d , pid : %d\n", (long)getpid(), x ,pid);
    }
    else if(pid == 0) { 
        x = 2;
        printf("자식 PID : %ld, x : %d\n", (long)getpid(), x);
    }
    else {
        printf("fork Fail! \n");
        return -1;
    }

    return 0;
}