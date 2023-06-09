pthread_t threads[5];
int done[5];

#ifndef _define_thread_
#define _define_thread_

void *thread_main(void *);

void thread_create();

void thread_verification(void** re);
#endif