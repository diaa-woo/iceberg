#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, temp) ((temp=x), (x=y), (y=temp))

int main() {
	int index, temp, min;
	int* arr;
	scanf("%d", &index);
	arr = calloc(index, sizeof(int));
	
	for(int i = 0; i<index; i++) {
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < index; i++) {
		min = i;
		for(int j = i; j < index; j++) {
			if(arr[min] > arr[j]) 
				min = j;
		}
		if(arr[min] == arr[i]) 
			continue;
		else
			SWAP(arr[i],arr[min], temp);
	}

	for(int i = 0; i<index; i++) {
                printf("%d ", arr[i]);
        }
	return 0;
}
