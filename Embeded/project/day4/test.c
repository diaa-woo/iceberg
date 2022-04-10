/*
    process(프로세스): 사용자가 작성한 프로그램이 운영체제에 의해 메모리 공간을 할당받아 실행 중인 것을 말함.
        이러한 프로세스는 프로그램에 사용되는 데이터와 메모리 등의 자원 그리고 스레드로 구성된다.
    thread(쓰레드):  프로세스(process) 내에서 실제로 작업을 수행하는 주체를 의미합니다.
        모든 프로세스에는 한 개 이상의 스레드가 존재하여 작업을 수행합니다.
        
    thread를 사용했을때의 장점:
        1. 문맥교환(context switching)시간이 짧다
        2. 메모리공유로 인하여 시스템 자원 소모가 줄어든다.
        3. 응답시간이 단축된다.

​
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_t threads[5];
int done[5];

void *thread_main(void *);

int main(void)
{
	int i;
	int rc;
	int status;
	
	printf("pid=%d\n", getpid());  //해당 프로그램의 프로세스 아이디 확인
	
	for (i = 0; i < 5; i++)
	{	
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("%d, %ld\n", i, threads[i]);
	}

	for (i = 4; i >= 0; i--)
	{
		done[i] = 1;
	         rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n",i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
            return -1;
		}
	}

	return 0;
}

void *thread_main(void *arg)
{
	int i;
	double result=0.0;

	printf("therad: %d, %d\n", (int)arg, getpid());

	while (!done[(int)arg])
	{
	   for (i=0; i < 1000000; i++)
   	   {
     	      result = result + (double)random();
   	   }
   	   printf("thread: %d, result = %e\n", (int)arg, result);
	}

	pthread_exit((void *) 0);
}