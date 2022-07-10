# SoftwareSerial

## Introduce
   
(Officially Document)   
The SoftwareSerial library allows serial communication on other digital pins of an Arduino board, using software to replicate the functionality (hence the name "SoftwareSerial"). It is possible to have multiple software serial ports with speeds up to 115200 bps. A parameter enables inverted signaling for devices which require that protocol.   
(직역: SoftwareSerial 라이브러리는 아두이노 보드의 디지털 핀들에서 serial 통신을 하게끔 하용해주며, 기능을 복제하는 소프트웨어를 사용한다. (그 후 이름을 "SoftwareSerial"이라고 부른다) 그것은 여러가지 소프트웨어 Serial 포트들을 115200 bps 만큼의 속도까지 올릴 수 있게 해준다. 하나의 파라미터는 디바이스들이 요구하는 프로토콜의 신호를 거꾸로 보내는 것을 가능하게 끔 해준다.(번역기 왈: 매개변수는 해당 프로토콜이 필요한 장치에 대해 역 신호를 활성화합니다.))

## Limitations(한계)
- It cannot transmit and receive data at the same time.(송수신이 같은 시간에 일어날 수 없음!)
- If using multiple software serial ports, only one can receive data at a time.(만약 여러개의 serial 포트들을 사용한다면, 동시간대에는 오로지 하나만 데이터를 받을 수 있음)

## Method

`SoftwareSerial(rxPin, txPin, inverse_logic)`
- rxPin: the pin on which to receive serial data.(수신)
- txPin: the pin on which to transmit serial data.(송신)
- inverse_logic: used to invert the sense of incoming bits (the default is normal logic). If set, SoftwareSerial treats a LOW (0v on the pin, normally) on the RX pin as a 1-bit (the idle state) and a HIGH (5V on the pin, normally) as a 0-bit. It also affects the way that it writes to the TX pin. Default value is false.(Active High, Active Low 상태를 결정지어주는 비트임. 보통은 LOW(0V)가 defalut로 설정되어 있으며, 바꾸고 싶으면 이산값으로 설정해두면 됨)
