/*
    process(프로세스): 사용자가 작성한 프로그램이 운영체제에 의해 메모리 공간을 할당받아 실행 중인 것을 말함.
        이러한 프로세스는 프로그램에 사용되는 데이터와 메모리 등의 자원 그리고 스레드로 구성된다.
    thread(쓰레드):  프로세스(process) 내에서 실제로 작업을 수행하는 주체를 의미한다.
        모든 프로세스에는 한 개 이상의 스레드가 존재하여 작업을 수행힌다.
        
    thread를 사용했을때의 장점:
        1. 문맥교환(context switching)시간이 짧다
        2. 메모리공유로 인하여 시스템 자원 소모가 줄어든다.
        3. 응답시간이 단축된다.

	Posix thread(pthread): ​병렬적으로 작동하는 소프트웨어의 제작을 위해 제공되는 표준 API
		Posix는 모든 Unix 계열의 포함되어 있는 시스템 중 하나이며, Unix 계열에 해당되는 OS는 Ubuntu, Mac 등이 있다.
		근데 꼭 Unix 계열만 이 pthread를 사용할 수 있는건 아니다. pthread-w32를 포함하면 윈도우도 사용 가능
	
	getpid() => 현재 작동하고 잇는 프로세스의 아이디를 불러와주는 함수

	pthread 헤더에 포함되어 있는 주요 명령어
		pthread_create : 쓰레드 생성 및 실행 
		  -> int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
			-> *thread 는 thread가 성공적으로 생성되었을때 생성된 thread를 식별하기 위해서 사용되는 thread 식별자이다.(이거 참조시킬때 주소값 넘겨줘야함)
			-> *attr 은 쓰레드 특성을 지정하기 위해서 사용하며, 기본 쓰레드 특성을 이용하고자 할 경우에 NULL 을 사용한다.
			-> *start_routine는 분기시켜서 실행할 쓰레드 함수이다.(얘도 주소 참조)(void 포인터를 사용하는 이유는 포인터 함수의 크기를 모르고, 최적화에 사용된다고 함)
			-> *arg는 위 start_routine 쓰레드 함수의 매개변수로 넘겨진다.(얘도 void 포인터 사용하는데, 이 때문에 여기에 값 입력할 때 void * 넣어줘야하는 이유인것 같다.(자세히는 모르겠음;;))
		pthread_join: 해당 쓰레드가 종료 할때까지 대기  
		  -> int pthread_join(pthread_t th, void **thread_return);
		  	-> th는 기다릴 thread의 식별자
			-> thread_return 은 thread의 리턴값. thread_return 이 NULL이 아닌 경우 해당 포인터로 쓰레드의 리턴 값을 받아올수 있다.(여기서 void 이중 포인터로 값을 받는데, 이는 저 함수 내에서도 포인터를 사용하여 값을 할당하고 역참조 시켜줘야 하기 때문이다.)
			-> 이중 포인터에 대한 내용: https://dojang.io/mod/page/view.php?id=553
		pthread_detach : pthread_create 를 통해 생성된 쓰레드를 떼어냄  
		pthread_exit : 현재 실행중인 쓰레드 종료  
		pthread_mutex_init : 뮤텍스 초기화  
		pthread_mutex_destory : 뮤텍스 제거  
		pthread_mutex_lock : 뮤텍스 잠금  
		pthread_mutex_unlock : 뮤텍스 잠금 해제  
		pthread_cancel : 쓰레드 취소  
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "main.h"

int main(void)
{
	int *re;
	printf("pid=%d\n", getpid());  //해당 프로그램의 프로세스 아이디 확인
	
	thread_create();
	thread_verification((void**)&re);
	return *re;
}
