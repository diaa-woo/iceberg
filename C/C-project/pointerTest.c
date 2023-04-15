#include <stdlib.h>
#include <stdio.h>

int* foo(int* fi) {
	
}

int main() {
	int* p;
	int* q;
	*p = 1;
	q = p+4;
	*q = 2;
	int a = *p;
	int b = *q;
	printf("%d %d", a, b);
	return 0;
}
