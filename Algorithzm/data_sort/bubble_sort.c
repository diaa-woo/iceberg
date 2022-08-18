#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, temp) ((temp = x), (x = y), (y = temp))

int main() {
	int index = 0, temp = 0;
	int* arr;
	scanf("%d", &index);
	arr = calloc(index, sizeof(int));  // 동적 할당

	for(int i = 0; i < index; i++) {
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < index; i++) {
		for(int j = index-1; j > i; j--) {
			if(arr[j] < arr[j-1]) {
				SWAP(arr[j], arr[j-1], temp);
			}
		}
	}

	for(int i = 0; i < index; i++) {
                printf("%d ", arr[i]);
        }
	
	return 0;
}

