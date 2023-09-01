[상위 문서로 이동](../../README.md)

# 그래프

**객체 사이의 연결 관계를 표현할 수 있는 자료구조**

## 그래프의 종류

방향성을 가지고 있느냐에 따라서 두 가지로 나뉜다.

### 무방향 그래프

각 노드들은 간선을 통해 양쪽 방향으로 갈 수 있음을 나타내며, 정점 A와 정점 B가 간선을 통해 연결되어 있다고 할 때, (A, B)로 나타낼 수 있다. 마찬가지로 (B,A)로도 나타낼 수 있기에 (A,B)=(B,A)가 된다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F951a157e-0349-45d2-b010-9b1cffc00bed%2F%E1%84%8F%E1%85%B2-001%20(5).png">

### 방향 그래프

해당 그래프의 간선은 단방향성의 성질을 지니고 있다. 방향 그래프에서의 간선은 *'>'* 를 이용하여 나타내며 <A, B>와 <B, A>는 서로 다른 간선이다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2Fa22062ad-310b-447b-b358-0a5c0f4eda80%2F%E1%84%8F%E1%85%B2-001%20(6).png">

## 네트워크

간선에 가중치를 할당하게 되면 간선의 역할이 두 정점간의 연결 관계를 나타낼 뿐만 아니라 연결 강도(연결 비용이라던가 연결 거리) 등의 보다 복잡한 관계를 표현할 수가 있다. 이렇게 간선에 비용이나 가중치가 할당된 그래프를 **가중치 그래프(weighted graph)** 혹은 **네트워크** 라 한다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F3897fa53-1b4f-49f6-834e-04e5b9d03503%2F%E1%84%8F%E1%85%B2-001%20(7).png">

위와 같은 그래프를 보면 A와 B 사이의 간선, 즉 (A,B)가 5라는 값을 나타내고 있는 것으로 둘 사이의 간선의 연결 비용이 5라는 의미를 내포한다.

## 정점의 차수

그래프에서 가장 중요한 개념 중 하나라고 말할 수 있는 **차수** 는 특정 정점에서 몇 개의 인접 정점에 연결되어 있는지에 대한 개수를 의미한다. 예를 들어 다음과 같은 그래프가 있다고 가정한다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F2e234d7b-9d01-4877-9518-b5d13b0f6a27%2F%E1%84%8F%E1%85%B2-001%20(10).png">

위와 같은 그래프에서 A,B,C,D 각각의 차수는 어떻게 될까?   
A=3, B=2, C=2, D=3이 될 것이다. 이렇게 구한 차수들의 합을 구하면 10이라는 결과가 나온다. 모든 차수의 합은 간선 수의 2배라는 것에 대해 알아두면 좋다.

> 정점의 차수 총합 = 간선의 개수 * 2

## 사이클

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F2e234d7b-9d01-4877-9518-b5d13b0f6a27%2F%E1%84%8F%E1%85%B2-001%20(10).png">

경로 중에서 반복되는 간선이 없을 경우에 이러한 경로를 **단순 경로**라고 한다. 위 그림을 살펴보면 A에서 B까지 가는 경로는 A,C,D,B가 있다.   
만약에 단순 경로의 시작 정점과 종료 정점이 동일하다면 이러한 경로를 사이클이라고 한다. 위 그림에서는 **A,C,D,A**를 예로 들 수 있다.

## 연결 그래프

무방향 그래프 G에 있는 모든 정점쌍에 대하여 항상 경로가 존재한다면 G는 연결되어 있다고 하며 그래프 G는 연결 그래프라고 부르며 그렇지 않은 그래프를 **비연결 그래프**라고 한다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2Fe1154cfe-2769-417e-a88c-980614162d38%2F%E1%84%8F%E1%85%B2-001%20(11).png">

## 완전 그래프

그래프에 속해있는 모든 정점이 서로 연결되어 있는 그래프를 완전 그래프라고 한다. 무방향 완전 그래프의 정점 수를 n이라고 하면, 하나의 정점은 n-1개의 다른 정점으로 연결되므로 간선의 수는 **n(n-1)x2** 가 된다. 만약 완전 그래프에서 n=4라면 간선의 수는 **4x3/2=6** 이 된다. 다음 그림과 같은 형태를 우린 **완전 그래프**라고 지칭한다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F8564e4a4-2b51-49a2-931d-18f0a1096fda%2F%E1%84%8F%E1%85%B2-001%20(12).png">

## C로 그래프 구현

- 객체: 정점의 집합과 간선의 집합
- 연산
  - `create_graph()`        : 그래프를 생성
  - `init(g)`               : 그래프 g 초기화
  - `insert_vertex(g,v)`    : 그래프 g에 간선 v 추가.
  - `insert_edge(g,u,v)`    : 그래프 g에 간선 (u,v) 추가
  - `delete_vertex(g,v)`    : 그래프 g에 정점 v를 삭제.
  - `delete_edge(g,u,v)`    : 그래프 g의 간선 (u,v) 생성
  - `is_empty(g)`           : 그래프 g가 공백 상태인지 확인
  - `adgacent(v)`           : 정점 v에 인접한 정점들의 리스트 반환
  - `destory_graph(g)`         : 그래프 g 제거    

### 그래프의 표현 방법

- 인접 행렬: 2차원 배열을 사용하는 그래프로 표현
- 인접 리스트: 연결 리스트를 사용하는 그래프로 표현

#### 인접 행렬

그래프의 정점 수가 n이라면 n*n의 2차원 배열인 인접 행렬로 나타낼 수 있다. **연결되어 있다면 1, 연결되어 있지 않다면 0(자기 자신도)** 을 넣음으로써 간단하게 나타낼 수 있다.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2F808e3f8b-892e-4e03-94af-65ae20f1053c%2F%E1%84%8F%E1%85%B2-001%20(14).png">

이러한 **인접 행렬**은 두 정점을 연결하는 **간선의 존재 여부를 바로 파악할 수 있다는 장점** 이 있다.   
시간 복잡도로 나타내도 O(1)로 나타낼 수 있다. 또한 정점의 차수 또한 O(n)의 시간 복잡도로 구할 수가 있다. 그러나 만약 정점의 개수에 비해 간선의 수가 너무 적다면 **희소 그래프가 되어 메모리 낭비가 아주 커지게 된다는 단점** 이 존재한다.

**코드**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType* g) {
    int r,c;
    g->n = 0;
    for(r=0; r<MAX_VERTICES; r++) {
        for(c=0; c<MAX_VERTICES;c++) {
            g->adj_mat[r][c]=0;
        }
    }
}

// Insert node
void insert_vertex(GraphType* g, int v) {
    if (((g->n)+1)>MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
}

// Insert edge
void insert_edge(GraphType* g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// print adjancency array
void print_adj_mat(GraphType* g){
    for(int i = 0; i<g->n; i++) {
        for(int j = 0; j<g->n; j++) {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i<4; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    print_adj_mat(g);

    free(g);

    return 0;
}
```

#### 인접 리스트

인접 리스트는 그래프를 표현함에 있어 각각의 정점에 인접한 정점들을 연결 리스트로 표시한 것이다. 각 **연결 리스트의 노드들은 인접 정접들을 저장**하게 되며 **각 연결 리스트들은 헤더 노드를 가지고 있고 이 헤더 노드들은 하나의 배열**로 구성되어 있다. 따라서 **정점의 번호만 알면 이 번호를 배열의 인덱스로 하여 각 정점의 연결 리스트에 쉽게 접근**할 수 있다.

인접 행렬과 다른 부분은 무방향 그래프를 나타낼 때 인데, 간선 (i,j)를 정의할 때 (j,i)를 한번 더 표현해주어야 한다. 또한 연결 리스트에 정점들이 입력되는 순서에 따라 연결 리스트 내에서 정점들의 순서가 달라질 수 있따.

<img src="https://velog.velcdn.com/images%2Fkysung95%2Fpost%2Ffa59a071-5074-40d1-96f3-0f736fc943a6%2F%E1%84%8F%E1%85%B2-001%20(15).png">

위 그림을 보면 연결리스트로 정점으로부터의 인접 정점들이 담긴 리스트가 생겨나는 것을 볼 수 있다.

```
0->1->2->3 : 3
1->0->2 : 2
2->0->1->3 : 3
3->0->2 : 2
```

**리스트를 추상화한 모습을 보면 정점의 개수가 4개, 간선이 5개인 그래프를 표현하기 위해서는 리스트가 총 4개 그리고 연결된 노드들은 총 10개가 필요하다는 걸 알 수 있다.**

인접 리스트를 통한 그래프의 특성을 알아보자면, 정점의 수가 n개이고 간선의 수가 e개인 무방향 그래프를 표시하기 위해선 **n개의 연결리스트**가 필요하고, **n개의 헤더 노드**와 **2e개의 노드**가 필요하다.


## 출처
https://velog.io/@kysung95/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-C%EB%A1%9C-%EA%B7%B8%EB%9E%98%ED%94%84%EB%A5%BC-%EB%A7%8C%EB%93%A4%EC%9E%90
