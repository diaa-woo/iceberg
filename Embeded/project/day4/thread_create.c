#include <stdio.h>
#include <pthread.h>
#include "main.h"

void thread_create() {
	int i;
	for (i = 0; i < 5; i++)
	{	
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("%d, %ld\n", i, threads[i]);
	}
}