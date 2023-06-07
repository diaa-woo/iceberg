#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>

typedef void*(*callback_t)(void*);
typedef unsigned long int uint32_t;

extern uint32_t thread_create(callback_t func, void *args);
extern int thread_join(uint32_t t_id);
extern int thread_exit(int state);

#endif