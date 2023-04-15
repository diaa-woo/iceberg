#include <stdio.h>
#include <time.h>

int main(void) {

    time_t t1;
    time(&t1);
    printf("%lld\n", t1);

    time_t t2;
    t2 = time(NULL);
    printf("%lld\n", t2);

    return 0;
}