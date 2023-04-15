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