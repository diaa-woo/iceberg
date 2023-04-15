#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t mem;

#define STORE_VALUE(mem, value) ((mem |= value) << 4)
#define READ_VALUE(mem, i) ((mem >> (i*4)) & 0x0F)
#define CLEAR_MEM(mem) (mem &= 0x00)

int main() {
	for(int i = 0; i<3; i++) {
		mem = STORE_VALUE(mem, (rand()%256));
	}
	for(int i = 0; i<3; i++) {
		printf("%d ", READ_VALUE(mem, i));
	}
	
	
	return 0;	
}
