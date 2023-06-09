#%%
import serial
# %%
if False:
    port = "COM6"
else:
    port= "/dev/ttyUSB0"
uart = serial.Serial(port, boudrate=115200)  # 리눅스는 다름!
# %%

msg = "OK";
uart.write(msg.encode())
# %%
data = uart.read(10)
data = data.decode()

uart.close()