#include <stdio.h>

typedef struct 
{
	unsigned int m:23;
	unsigned int e:8;
	unsigned int s:1;
}raw_float_t;

typedef union
{
	raw_float_t _raw;
	float f;
}float_t;

int main() 
{
	float_t n;
	scanf("%f", &n.f);
	printf("%f\n", n.f);
	printf("%d %d %d\n", n._raw.s, n._raw.e, n._raw.m);
    return 0;
}
