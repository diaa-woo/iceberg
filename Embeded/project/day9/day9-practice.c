/*-------------------------------------------------------------------------------------
0. 0으로 초기화한 s,b 생성
- s, b 범위(0~3), 연산 규칙 
	-> 컴퓨터에서는 자원이 유한하기에 수학과 달리 이를 잡아줘야함!
	-> 속도(int), 메모리(char) 
1. 난수로 3개의 숫자생성(P_n; n=3)
- 위처럼 범위와 연산 규칙을 잡아줘야 함!
- n 변수, n 배열(우선 적합), n 구조체
- 의사(가짜)난수(수열 이용(1_C_32)) srandom(): seed 설정, random(): seed 기준 무작위 수열 생성 (0 ~ MAX_INT) 반환 -> C Standard Library

srandom(time(NULL));
P[0] = random() % 10;
do {
  P[1] = random() % 10;
} while(P[0] == P[1]);
do {
   P[2] = random() % 10;
} while(P[0] == P[2] || P[1] == P[2]);

2. 사용자 숫자 3개 입력(U_n; n=3)
- n 배열, U[3]
- scanf("%d %d %d", &U[0], &U[1], &U[2]);
3. P_n과 U_n이 같은지 비교/판단
3-1. P_n과 U_n이 같으면 s 값 1 증가
for(int i = 0; i<3; i++) {
  if(P[i] == U[i]) s++;
}  //한번에 비교하여 한번에 스트라이크를 표시할 수 있는 방법이 있음! (난수와 사용자 입력 비트를 만들어 AND 연산을 해주면 됨!
3-2. n != m일 때, P_m == U_n 이 true일 때 b값 증가
for(int i = 0; i<3; i++) {
  for(int j = 0; j<3; j++) {
    if(i==j) continue;
    if(P[m]==U[n]) b++;
  }
}

프로그래밍의 본질이란 결국 로직을 잘 짜는 것이 제일 중요하다.
결국 로직을 잘 짜는 것이 가장 중요한 것, 위의 로직을 짠 내용들이 상당히 중요하다.(수학이 로직을 짜는데 큰 역할을 하기에 결국 중요하다)
단순히 해당 문제에 대해서 그냥 로직에 맞춰 코드를 짜는 것은 그냥 코더이다.
원인 중심론 vs 결과 중심론
-> 속도: 결과 중심론 > 원인 중심론
-> 공부량 vs 재사용량: 원인 중심론 >>>> 결과 중심론
-> 결론: 시간이 좀 더 걸리더라도 원인 중심의 프로그래밍을 하는게 더 중요하다!
프로그램이라는 건 결국 패턴 찾기(규칙을 찾아가는 과정(물론 바로 안나옴! 어느정도 변형을 해야함(수학...)))


로직설계-------------------------------------------------------------------------------*/

/*세부전략---------------------------------------------------------------------------
P,U는 전역변수 사용
0. 입력 -> 처리 -> 출력
1. 초기화: void init(void)
- P_n 생성
2. 입력: void input(void)
- U_n 대입
3. 처리: void process(void)
- P_n, U_n 비교, P_m과 U_n 비교
4. 출력: void show(void)
- s,b
if(s==3) 종료
else 2. 실행

지역변수 사용시: 포인터 사용으로 복잡성 늘어남
전역변수 사용시: 어떤 함수가 전역변수의 값을 바꾸었는지 확인할 수 있도록 해주어야함(그래야 디버깅이 편함)
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ITEMS 3
#define DEBUG 1

int P[MAX_ITEMS];
int U[MAX_ITEMS];
int s = 0,b = 0;

void init(void) {
  srandom(time(NULL));
  P[0] = random() % 10;
  do {
    P[1] = random() % 10;
  } while(P[0] == P[1]);
  do {
    P[2] = random() % 10;
  } while(P[0] == P[2] || P[1] == P[2]);
  return;
}

void input(void) {
  scanf("%d %d %d", &U[0], &U[1], &U[2]);
  return;
}

void process(void) {
  /*for(int i = 0; i<3; i++) {
    if(P[i] == U[i]) s++;
  }
  for(int i = 0; i<3; i++) {
    for(int j = 0; j<3; j++) {
      if(i==j) continue;
      if(P[i]==U[j]) b++;
    }
  }*/
  for (int i = 0; i<3; i++) {  //줄이기
    for(int j = 0; j<3; j++) {
      if(i==j) {
        if (P[i] == U[i]) s++;
      }
      else {
        if(P[i] == U[j]) b++;
      }
    } 
  }
  return;  
}

void show(void) {
  printf("s: %d b: %d\n",s,b);
  if(DEBUG) printf("%d %d %d\n", P[0], P[1], P[2]); 
  return;
}

int main(void) {
  init();
  do {
    s = b = 0;
    input();
    process();
    show();
  } while(s!=3);
  return 0;
}










