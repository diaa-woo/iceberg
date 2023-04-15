#include <stdio.h>
#include <time.h>

int main(void) {
    time_t t;
    t = time(NULL);     // time() 함수를 통해서 현재 시간 반환
    printf("%lld", t);
    return 0;
}