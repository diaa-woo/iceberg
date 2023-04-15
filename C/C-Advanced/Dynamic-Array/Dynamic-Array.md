# Dynamic Array

## 동적 배열이란?

동적 배열은 heap을 이용하여 배열의 크기를 컴파일 단계가 아닌 실행시간에 가변적으로 바꿀 수 있는 배열을 말한다.

## 1차원 동적 배열 생성하기
 
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Array's size is: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i< size; i++) {
        arr[i] = i;
    }

    for (int i = 0; i< size; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}
```

C언어로 동적 배열을 생성하는 방법을 다음과 같다. malloc 함수를 사용하여 Heap에 원하는 크기만큼의 동적 메모리를 생성하고 사용하면 된다. 배열은 연속된 메모리의 공간으로써, 배열의 한 지점을 참조한다는 것은 곧 포인터와 같은 개념이 될 수 있다. 그렇기에 메모리의 포인터로 동적으로 생성하고 싶은 사이즈만큼의 공간을 할당하면 된다.

