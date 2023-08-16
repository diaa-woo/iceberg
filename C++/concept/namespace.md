[상위 문서로 이동](../README.md)

# namespace

## std

`std`는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 **이름 공간(namespace)** 이다.

표준 입출력 및 객체 제어에 도움을 준다.

## namespace란?

그렇다면 이름 공간은 정확히 무엇일까? 말 그대로 어떤 정의된 객체에 대해 **어디 소속인지** 지정해주는 것과 동일하다.

코드의 크기가 늘어남에 따라, 혹은 다른 사람들이 쓴 코드를 가져다 쓰는 경우가 많아지면서 중복된 이름을 가진 함수들이 많아졌다. 이에 C++에서는 이를 구분하기 위해, 같은 이름일지라도 소속된 **이름 공간**이 다르면 아예 다른 것으로 취급하게 되었다.

```cpp
std::cout
```

위의 경우, `std`라는 이름 공간에 정의되어 있는 `cout`을 의미한다. 만약에 `std::` 없이 그냥 `cout`이라고 한다면 컴파일러는 `cout`을 찾지 못하게 된다.

### 공간 정의

다음과 같다. 예를 들어 `header1.h`, `header2.h`과 같은 두 개의 헤더 파일을 생성한다고 하자.

```cpp
// header1.h
namespace header1 {
    int foo();
    void bar();
}
```

```cpp
// header2.h
namespace header2 {
    int foo();
    void bar();
}
```

같은 함수 이름일지라도 다른 이름 공간에 정의되어 있기 때문에 컴파일러는 서로 다른 함수라고 인식한다.

### 함수 호출

자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 앞에 이름 공간을 명시하지 않아도 된다.

```cpp
#include "header1.h"

namespace header1 {
    int func() {
        foo()   // 알아서 header1::foo()가 실행된다.
    }
}
```

이렇다고 해서 *header1* 이름 공간안에 *header2*의 함수들을 호출하지 못한다는 거는 아니다. 그냥, 아래처럼 붙여주면 된다.

```cpp
#include "header1.h"
#include "header2.h"

namespace header1 {
    int func() {
        foo();              // 알아서 header1::foo()가 실행된다.
        header2::foo();     // header2::foo() 가 실행된다.
    }
}
```

반면, 어떠한 이름 공간에도 소속되지 않는 경우라면 아래와 같이 명시적으로 이름 공간을 지정하면 된다.

```cpp
#include "header1.h"
#include "header2.h"

int func() {
    header1::foo()
}
```

하지만 만일 위 같은 `foo()` 함수를 여러 번 반복적으로 호출하게 되는 경우 앞에 매번 `header1::`을 붙이기가 상당히 귀찮을 것이다. 그래서 아래와 같이 `using`을 이용하여 사용할 수도 있다.

```cpp
#include "header1.h"
#include "header2.h"

using header1:foo;
int main() {
    foo();
}
```

그런데 만일 해당 함수뿐만 아니라 그냥 `header1` 이름 공간 안에 정의된 모든 것들을 `header1::` 없이 사용하고 싶다면 아예 `using namespace header1`를 갖다 박아도 된다.

```cpp
#include "header1.h"
#include "header2.h"

using namespace header1;
int main() {
    foo();
    bar();
}
```

물론 이렇게 한다고 다른 이름 공간의 함수를 불러오지 못하는 건 아니다. 다만 같은 이름 함수면 제대로 명시해주는 것이 중요하다.

```cpp
#include "header1.h"
#include "header2.h"
using namespace header1;

int main() {
  header2::foo();  // header2 에 있는 함수를 호출
  foo();           // header1 에 있는 함수를 호출
}
```

## 주의 사항

보통 표준 라이브러리에 있는 함수를 호출하는 과정을 조금이나마 더 편하게 하기 위해 `using namespace std`를 많이 사용하고 있다. 하지만 이를 포함해, 어떠한 이름 공간을 사용하겠다라고 선언하는 것은 권장하지 않고 있다. 왜냐하면 `std`등 선언된 이름 공간에서의 함수를 겹쳐쓰면, 오류를 발생시키기 때문이다.

특히나 C++ 표준 라이브러리는 매우매우 건대하므로, 수 많은 함수들이 존재하고 있다. 자칫 잘못하다가 이름을 겹치게 사용한다면, 고치느라 시간을 많이 잡아먹을 것이다. 게다가 std에서는 매번 수 많은 함수들이 새롭게 추가되고 있기 때문에 C++ 버전이 바뀔 때 마다 기존에 잘 작동하던 코드가 이름 충돌로 인해 동작하지 않게 되리라는 문제가 발생할 수 있다.

따라서 권장하는 방식은 **`using namespace std;` 같은 것은 사용하지 않고, `std::`를 직접 앞에 붙여서 `std`의 이름공간의 함수이다 라고 명시해주는 것이 좋다**. 또한 직접 작성하는 코드는 자신만의 이름 공간에 넣어 혹시 모를 이름 충돌로부터 보호하는 것이 중요하다.

## 이름 없는 이름 공간

좀 재밌는 점은, C++에서는 이름 공간에 굳이 이름을 설정하지 않아도 괜찮다.

이 경우 해당 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있게 된다. 이 경우 마치 `static` 키워드를 사용한 것과 같은 효과를 낼 수 있다.

```cpp
#include <iostream>

namespace {
    // 이 함수는 이 파일 안에서만 사용이 가능하다.
    int onlyInThisFile() {}     // = static int onlyInThisFile()

    int only_in_this_file = 0;  // = static int only_in_this_file;
}

int main() {
    onlyInThisFile();
    only_in_this_file = 3;
}
```