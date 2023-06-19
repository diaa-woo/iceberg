#include <stdio.h>
#include <stdlib.h>

int** graph;
int* visited;

int DFS(int cur, int n) {
    int i;
    visited[cur] = 1;  // 방문 체크
    printf("%d ", cur);  // 정점 출력
    for(i=1; i<=n; i++) {
        if(graph[cur][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n = 0, m = 0, v = 0, a, b;
    scanf("%d %d %d", &n, &m, &v);

    graph = (int**)calloc((n+1), sizeof(int *));  // 초기화 필요! malloc -> calloc

    for(int i = 0; i<=n; i++) {
        graph[i] = (int *)calloc((n+1), sizeof(int));
    }

    // graph[10][10] = 5;
    // printf("%d", graph[10][10]);

    visited = (int *)calloc((n+1), sizeof(int));

    for(int i = 0; i<m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(v, n);
    return 0;

}