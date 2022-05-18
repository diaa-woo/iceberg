#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void error_handling( char *message) ;
int main( int argc, char *argv[] ){
    int serv_sock;
    int clnt_sock;

    // sockaddrn_in : 소켓 주소와 틀을 형성해 주는 구조체로 PF_INET일 경우
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    //TCP, ipv4
    serv_sock = socket( PF_INET, SOCK_STREAM, 0);
    if( serv_sock == -1 ) error_handling("socket error");

    //주소를 초기화한 후 IP주소와 포트 지정
    memset( &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET; // ipv4
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1"); // ip주소
    serv_addr.sin_port=htons(8080);

    //소켓과 서버주소 바인딩
    if( bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind error");
    if( listen(serv_sock, 5)==-1 )
        error_handling("listen error");

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    
    if( clnt_sock == -1 ) error_handling("accept error");

    char request[1024];
    int bytes_received = recv( clnt_sock, request, 1024, 0);
    printf("Received %d bytes.\n", bytes_received);
    printf("%s\n", request);

    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type: text/plain\r\n\r\n"
        "Local time is: ";
    int bytes_sent = send(clnt_sock, response, strlen(response), 0);
    time_t timer;
    time(&timer);
    char *time_msg = ctime( &timer );
    bytes_sent = send(clnt_sock, time_msg, strlen(time_msg), 0);
    close( clnt_sock );
    close( serv_sock );
    return 0;
}
void error_handling( char *message ){
    fputs( message, stderr);
    fputc('\n', stderr);
    exit(1);
}
