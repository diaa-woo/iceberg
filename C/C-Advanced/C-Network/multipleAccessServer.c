#define _XOPEN_SOURCE 700
#define BUF_SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);
void read_childproc(int sig);  //Signal Handler

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;

    pid_t pid;
    struct sigaction act;

    socklen_t adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];

    if(argc!=2)
    {
        printf("Usage : %s <port> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* sigaction 구조체 초기화*/
    act.sa_handler= read_childproc;
    sigemptyset(&act.sa_mask);  // 0으로 초기화
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);  //시그널 등록(자식 프로세스 종료시 read_childproc 호출)

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓 생성

    /* 서버 주소 정보 초기화 */
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv_adr.sin_port=htons(atoi(argv[1]));

    /* 서버 주소정보를 기반으로 주소할당 */
    if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==1) 
        error_handling("bind() error");

    /* 서버가 클라이언트의 연결요청 준비를 완료 */
    if(listen(serv_sock,5)==1)
        error_handling("listen() error");

    while(true)
    {
        adr_sz = sizeof(clnt_adr);
        clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);

        /* 서버가 클라이언트의 요청을 수락 */
        if(clnt_sock == -1)
            continue;
        else
            puts("New client connected...");
        
        pid = fork();
        if(pid==-1) //소켓 생성 실패시
        {
            close(clnt_sock);  // 클라이언트와 연결을 위해 생성한 소켓 연결종료
            continue;
        }

        if(pid==0)  // 서버의 자식 프로세스의 경우
        {
            close(serv_sock);  //서버의 부모 프로세스만 이 소켓에 대한 파일 디스크럽터를 갖게 하기 위함

            while((str_len==read(clnt_sock, buf, BUF_SIZE))!=0) //클라이언트로부터 데이터를 모두 수신하여
                write(clnt_sock, buf, str_len);  //다시 클라이언트로 에코

            close(clnt_sock);  // 클라이언트에 대한 에코 서비스를 모두 완료했으므로 소켓 연결 종료
            puts("client disconnected");

            return 0;
        }
        else 
            close(clnt_sock);  // 서버의 자식 프로세스만 이 소켓에 대한 파일 디스크럽터를 갖게 하기 위해
    }

    close(serv_sock); // 서버 부모 프로세스에서 소켓을 종료
    return 0;
}

void error_handling(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);  // -1
}

void read_childproc(int sig)
{
    pid_t pid;
    int status;
    pid=waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status))
    {
        printf("removed proc id: %d \n", pid);
        // printf("removed proc send: %d\n, WEXITSTATUS(status"));
    }
}