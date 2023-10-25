# TGSI

TGSI(Tungsten Graphics Shader Infrastructure)는 셰이더를 표현하기 위한 중간 언어이다. `Gallium`은 본질적으로 셰이더 기반이기에 셰이더는 API의 중요한 부분인데, TGSI가 이를 담당해줄 수 있다. 아울러 TGSI는 모든 드라이버에서 사용되는 유일한 중간 표현이다.

## 시작 - 서문

opcode라고 알려진 모든 TGSI 명령어는 임의의 정밀도 부동 소수점 4성분 벡터에서 작동된다. opcode에는 `dst`라고 하는 최대 한 개의 대상 레지스터와 `src0`~`src2`라고 하는 0~3개의 소스 레지스터가 있을 수 있으며 하나만 있는 경우 간단히 `src`를 가질 수 있다.

`I2F`와 같은 일부 명령어는 벡터 구성요소를 정수로 재해석하는 것을 허용한다. 다른 명령어에서는 레지스터를 배정밀도의 2성분 벡터로 사용할 수 있다. 이 부분은 이중 ISA 참조

한 명령어가 스칼라 결과를 가질 경우, 일반적으로 해당 결과는 dst의 각 구성 요소에 복사된다. 이런 경우 결과는 dst로 복제되었다고 한다. RCP는 이와 같은 명령어 중 하나이다.