#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "sys/socket.h"
#include "fcntl.h"
void main(){
    int fd1, sd1, sd2;
    printf("gettablesize() = %d\n", getdtablesize());
    fd1 = open("/etc/passwd", O_RDONLY, 0);
    printf("/etc/passwd's fd = %d\n", fd1);

    sd1 = socket(PF_INET, SOCK_STREAM, 0);
    printf("stream socket descriptor = %d\n", sd1);

    sd2 = socket(PF_INET, SOCK_DGRAM, 0);
    printf("datagram socket descriptor = %d\n", sd2);

    close(fd1);
    close(sd2);
    close(sd1);
}
