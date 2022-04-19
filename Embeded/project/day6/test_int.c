#include <stdio.h>

typedef struct RAW_DATA 
{
    unsigned int 
			d0:1, d1:1, d2:1, d3:1, d4:1, d5:1, d6:1, d7:1;
			//LSB: d0, MSB: d7 
} raw_data_t;

typedef union CHAR
{
    raw_data_t _raw;
    char ch;
}char_t;

void bin_show(char_t val)
{
    printf("%d%d%d%d-%d%d%d%d\n", 
        val._raw.d7, 
        val._raw.d6, 
        val._raw.d5, 
        val._raw.d4, 
        val._raw.d3, 
        val._raw.d2, 
        val._raw.d1, 
        val._raw.d0);
}

int main() 
{
    char_t n;
    scanf("%d", &n.ch);

    printf("%d\n", n.ch);
    bin_show(n);
	
    return 0;
}
