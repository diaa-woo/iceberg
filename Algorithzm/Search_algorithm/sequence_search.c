#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, want = 0, status = 0, k = 0;

    scanf("%d %d", &n, &want);

    int *arr = calloc(n, sizeof(int));

    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    while(k != n) {
        if(arr[k] == want) {
            status = 1;
            break;
        }
        k++;
    }

    if(status)
        printf("%d", k);
    else
        printf("Not Found");

    return 0;

}