#include <pthread.h>
#include "main.h"

void *thread_main(void *arg)
{
	double result=0.0;

	printf("therad: %d, %d\n", (int)arg, getpid());

	while (!done[(int)arg])
	{
	   for (int i=0; i < 1000000; i++)
   	   {
     	      result = result + (double)random();
   	   }
   	   printf("thread: %d, result = %e\n", (int)arg, result);
	}

	pthread_exit((void *) 0);
}