#include <stdio.h>
#include <pthread.h>
#include "main.h"

void thread_verification(void** re) {
	int i;
	int rc;
	int status;
	for (i = 4; i >= 0; i--)
	{
		done[i] = 1;
	    rc = pthread_join(threads[i], (void **)&status);  //이중 포인터 전달
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n",i, status);
			*re = &rc;
		}
		else
		{
			rc = -1;
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
            *re = &rc;
		}
	}
}
