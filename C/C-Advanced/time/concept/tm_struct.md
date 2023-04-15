# tm_struct

tm 구조체는 시간을 우리가 알아볼 수 있게 세세하게 변수로 나누어서 만들어져 있는 구조체이다. 적어도 `time_t`보다는 훨씬 친절한 놈이다.

## 구조체 구성

```C
struct tm {
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};
```

주석에 "[]" 구간으로 표현이 되어 있다. 이 말은 끝에 있는 포함한다는 뜻이다. 예시를 들어 주석 중 **'분'**을 나타내는 변수 **tm_min**를 보면 **0분을 포함하여 59분까지** 표현을 하는 **정수**로 사용될 것이다. 라고 쓰여있다.

알아둬야 할 부분.

- '월'을 사용하는 `tm_mon`을 보면 0~11이다. 이는 0월~11월을 표현한다는 뜻인데, 우리는 12월까지 사용하기에 이 요소를 사용하려면 **+1**을 해야 한다.
- '연도'를 나타내는 tm_year을 보면 years since 1900이라고 나와있다. 즉 **"tm_year은 1900년부터 숫자를 나타낼거니깐 니가 현재 연도를 가지고 오려면 1900년도