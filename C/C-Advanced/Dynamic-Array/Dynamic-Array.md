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

<img src ="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FRpLhi%2FbtqUYgWkbAa%2FRawB5OIcsTVrks7irIEda1%2Fimg.png">

먼저 포인터 변수를 선언하고 Heap에 동적으로 만들어 놓은 배열의 시작주소를 저장해주면 우리는 포인터 변수를 통해 동적 할당된 메모리에 접근이 가능하다.

> 만약 'NULL 포인터를 역참조하고 있습니다.' '버퍼 오버런 발생' 같은 문구가 출력되면 파일 확장자를 의심하라. C++에서는 malloc함수를 사용할 때 new라는 연산자를 사용하는 것으로 바뀌었기 때문.

## 2차원 동적 배열 생성

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("배열의 사이즈: ");
    scanf("%d", &size);

    // size 개수만큼의 행들 생성
    int** arr = (int**)malloc(sizeof(int*) * size);

    // size 개수만큼의 열들 생성
    for(int i = 0; i<size; i++) {
        arr[i] = (int*)malloc(sizeof(int) * size);
    }

    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) {
            arr[i][j] = i + j;
        }
    }

    // 배열의 값 출력
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) {
            printf("arr[%d][%d] : %d    ", i, j, arr[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for(int i = 0; i<size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
```

1차원 배열을 동적 생성할 경우 포인터 하나를 가지고 동적 할당한 메모리의 주소의 첫번째 위치를 참조하는 식으로 동적 배열을 생성하였다. 2차원 배열도 원리는 같지만, 2차원 포인터를 사용해야 한다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbLgrTd%2FbtqUZu7Fy0B%2FCLakT68BO3ilAPyUcHgm01%2Fimg.png">

출처: https://coding-factory.tistory.com/672