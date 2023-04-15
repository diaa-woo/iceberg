#include <stdio.h>
#include <stdint.h>

#define REGISTER_DATA(mem, data) (((mem) << 4) | (data))
#define CALL_DATA(mem, loc) (((mem) >> 4*((loc)-1)) & 0x0f)

uint32_t change_index_value(uint32_t mem, uint32_t mem_cp, uint32_t loc, uint32_t data)  
{ 
	mem_cp = (!CALL_DATA(mem, loc) << loc * 4); 
	mem |= mem_cp; 
	mem_cp = !(data << loc); 
	mem &= mem_cp; 
	return mem;
}

uint32_t mem = 0;
uint32_t mem_cp = 0;


int main()
{
	mem = 2;
	mem = REGISTER_DATA(mem, 1);
	mem = REGISTER_DATA(mem, 2);
	mem = REGISTER_DATA(mem, 1);
	mem = REGISTER_DATA(mem, 2);
	printf("%d", CALL_DATA(mem, 5));
	mem = change_index_value(mem, mem_cp, 1, 3);
	printf("%d", CALL_DATA(mem, 5));
	return 0;
}
