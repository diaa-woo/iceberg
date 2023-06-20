[상위 문서로 이동](../../README.md)

# 계수 정렬

- 비교연산을 하지 않아 시간 복잡도가 $O(n+(데이터의\,최댓값)k)$ 인 정렬 방식이k다.
- 이름 그대로 배열 내에 특정한 값이 몇번 등장했는지에 따라 정렬을 수행한다.

## 코드

``` C
// k == max number
// n == number of data in A
void counting_sort(int A[], int B[], int C[]){
 
    /* 카운팅 배열 0으로 초기화 */
    for (int i = 0 ; i <= k ; i++){
        B[i] = 0;
    }
 
    /* 카운팅 값 갱신  */
    for (int i = 1 ; i <= n ; i++){
        B[A[i]] = B[A[i]] + 1;
    }
 
    /* 누적합 계산 */
    for (int i = 1 ; i <= k ; i++){
        B[i] = B[i] + B[i-1];
    }
 
    /* 결과 배열에 값 넣기 */
    for (int i = n ; i >= n ; i--){
        C[B[A[i]]] = A[i];
        B[A[i]] = B[A[i]] - 1;
    }
}
```

count, sum 배열 두개를 만들어 사용한다.

## 분석
입력받은 배열의 데이터 개수가 k보다 작다면 굉장히 유용하지만, K가 더 큰 경우 비효율적인 알고리즘이 될 수 있다.

## 출처
https://jeonyeohun.tistory.com/103