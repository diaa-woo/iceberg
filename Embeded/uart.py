from curses import baudrate
import serial
import time

uart = serial.Serial("COM6", baudrate=115200);
time.sleep(1)

data = bytearray([0x00 for _ in range(2048)])

if(uart.read() == b'\x00' and uart.read()== b'\x01' and uart.read() == b'\x02'):
    data[-1] = 0xFF
    uart.write(data)
    print("ok")
else:
    print("error")