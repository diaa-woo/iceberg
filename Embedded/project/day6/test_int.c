#include <stdio.h>

typedef struct RAW_DATA 
{
    unsigned int 
		d0:1, d1:1, d2:1, d3:1, d4:1, d5:1, d6:1, d7:1, d8:1, d9:1, d10:1, d11:1, d12:1, d13:1, d14:1, d15:1, d16:1, d17:1, d18:1, d19:1, d20:1, d21:1, d22:1, d23:1, d24:1, d25:1, d26:1, d27:1, d28:1, d29:1, d30:1, d31:1;
			//LSB: d0, MSB: d7 
} raw_data_t;

typedef union CHAR
{
    raw_data_t _raw;
    char ch;
}char_t;

void bin_show(char_t val)
{
    printf("%d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d-%d%d%d%d\n", 
        val._raw.d31, 
        val._raw.d30, 
        val._raw.d29, 
        val._raw.d28, 
        val._raw.d27, 
        val._raw.d26, 
        val._raw.d25, 
        val._raw.d24,
        val._raw.d23, 
        val._raw.d22, 
        val._raw.d21, 
        val._raw.d20, 
        val._raw.d19, 
        val._raw.d18, 
        val._raw.d17, 
        val._raw.d16,
        val._raw.d15, 
        val._raw.d14, 
        val._raw.d13, 
        val._raw.d12, 
        val._raw.d11, 
        val._raw.d10, 
        val._raw.d9, 
        val._raw.d8,
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
