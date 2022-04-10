from socket import *

s_ip = 'localhost'
s_port = 9999

s_sock = socket(AF_INET, SOCK_DGRAM)  # AF_INET: IPv4, SOCK_DGRAM: (검사결정 방식) UDP방식
s_sock.bind((s_ip, s_port))

s_sock.settimeout(10)  # 10초 대기후 종료

data, c_addr = s_sock.recvfrom(1024)  # 이 포트에서 받아줌(괄호안에는 출발지를 물어봄)

print('Receive from', c_addr) 
print('Obtained ', data.decode('utf-8'))  # receive 받은 데이터 해독

s_sock.close()