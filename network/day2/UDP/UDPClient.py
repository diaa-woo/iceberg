from socket import *

s_ip = 'localhost'
s_port = 9999

c_sock = socket(AF_INET, SOCK_DGRAM)

c_sock.sendto('안녕, server!'.encode('utf-8'), (s_ip, s_port))  # sendto: 보내줌, encode: 데이터 utf-8로 변환후 전송

c_sock.close()

'''
서버                                            클라이언트
메소드      의미                                 메소드     
socket      전화기를 준비하여 소켓에 연결          socket
recvfrom    듣기                                 sendto
sendto      말하기                               recvfrom
close       전화 끊기                            close
'''