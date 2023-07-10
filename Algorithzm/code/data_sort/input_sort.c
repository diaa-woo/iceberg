#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,temp) ((temp = x), (x = y), (y = temp))

int main() {
	int index, temp, min;
	int* arr;
	scanf("%d", &index);
	arr = calloc(index, sizeof(int));

	for(int i = 0; i<index; i++) {
		scanf("%d", &arr[i]);
	}

	for(int i = 1; i<index; i++) {
		min = i;
		for(int j = i; j>=0; j--) {
		      if(arr[j] < arr[j-1]) {
			      SWAP(arr[j], arr[j-1], temp);
		      }
		}
	}

	for(int i = 0; i<index; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

