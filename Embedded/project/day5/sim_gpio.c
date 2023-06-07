#include <stdio.h>
#include <stdlib.h>
#include "thread.h"

// Task 1
int gpio_pin_1_in_value_reg;  //0 or 1
int gpio_pin_1_out_value_reg;  //0 or 1
int gpio_pin_1_direct_reg = 1;  //0(Out) or 1(IN)

void in()
{
    fprintf(stderr, "IN: %d", gpio_pin_1_in_value_reg);
}

void out() 
{
    fprintf(stderr, "OUT: %d", gpio_pin_1_out_value_reg);
}

void* gpio_pin_1(void* args) 
{
    while(1) 
    {
        if(gpio_pin_1_direct_reg) 
        {
            in();
        }
        else
        {
            out();
        }
    }
}

// Task 0(Main)
int main() 
{
    uint32_t t_id;
    t_id = thread_create(gpio_pin_1, 0);
    while (1) {
        int d, v;
        scanf("%d", &d);  //direction
        gpio_pin_1_direct_reg = d;
        scanf("%d", &v);  //value
        if(d)  {  //out_value_reg
            gpio_pin_1_out_value_reg = v;
        }
        else {  //in_value_reg
            gpio_pin_1_in_value_reg = v;
        }
    }
    return 0;
}