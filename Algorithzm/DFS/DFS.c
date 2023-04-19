#include <stdio.h>
#include <stdlib.h>

int** graph;
int* visited;

int DFS(int cur, int n) {
    int i;
    visited[cur] = 1;
    for(i=1; i<=n; i++) {
        if(graph[cur][i] == 1 && visited[i] == 0) {
            printf("%d ", i);
            DFS(i, n);
        }
    }
}

int main() {
    int n = 0, m = 0, v = 0, a, b;
    scanf("%d %d %d", &n, &m, &v);

    graph = (int**)malloc(sizeof(int*) * (n+1));

    for(int i = 0; i<=n; i++) {
        graph[i] = (int *)malloc(sizeof(int) * (n+1));
    }

    visited = (int *)malloc(sizeof(int) * (n+1));

    for(int i = 0; i<m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(v, n);
    return 0;

}