[상위 문서로 이동](../README.md)

# new, delete

메모리를 관리하는 문제는 언제나 중요한 문제이다. 프로그램이 정확하게 실행되기 위해서는 컴파일시에 모든 변수의 주소값이 확정되어야만 했다. 하지만, 이를 위해서는 프로그램에 많은 제약이 따르기 때문에 프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 **힙(heap)**이라는 공간이 따로 생겼다.

하지만 이전에 컴파일러에 의해 어느정도 안정성이 보장되는 **스택(Stack)**과는 다르게 힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임도 크다.

C언어에서는 `malloc`, `free` 함수를 지원하여 힙 상에서의 메모리 할당을 지원햇었다. C++에서도 마찬가지로 `malloc`과 `free`를 사용할 수는 있다.

하지만, 언어 차원에서 지원하는 것은 바로 `new`와 `delete`이다. `new`는 말 그대로 `malloc`과 대응하는 것으로 메모리를 할당하고 `delete`는 `free`에 대응되는 것으로 메모리를 해제한다. 어떻게 사용하는 것일까?

ex)
```c++
#include <iostream>

int main() {
    int* p = new int;
    *p = 10;

    std::cout << *p << std::endl;

    delete p;
    return 0;
}
```

성공적으로 컴파일 했다면 결과는 `10`이 나올 것이다. 위와 같이 `int` 영역이 잘 할당되어서 10이 출력되었음을 알 수 있다.

위와 같이 `new`를 이용하여 특정 자료형 크기의 공간을 할당하여 그 주소값을 포인터 변수에 집어넣을 수 있다. 즉, 아래와 같다. T는 특정 자료형이다.

```cpp
T* pointer = new T;
```

이제 pointer 위치에 할당된 공간에 값을 집어넣고 출력하면 해당 값이 나오는 것을 확인할 수 있다.

```cpp
*p = 10;
```

마지막으로 할당된 공간을 해체하는 방법은 `delete`를 사용하면 된다. `delete`로 해제할 수 있는 메모리 공간은 사용자가 `new`를 통해서 할당된 공간만 가능하며, 다른 지역 변수를 무리하게 해제하려고 하면  `heap`이 아닌 공간을 해제하려 한다고 옹류난다.

```cpp
delete p;
```

## new로 배열 할당하기

```cpp
#include <iostream>

int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for(int i = 0; i<arr_size; i++) {
        std::cin >> list[i];
    }
    for(int i = 0; i<arr_size; i++) {
        std::cout << i << "the element of list : " << list[i] << std::endl;
    }
    delete[] list;
    return 0;
}
```

`list`에 `new`를 이용하여 크기가 `arr_size`인 `int` 배열을 생성하였다. 그리고 배열을 생성할 때에는 `[]`를 이용하여 배열의 크기를 넣어준다. 아래는 배열 생성 코드이다.

```cpp
T* pointer = new T[size];   // T는 임의의 자료형이다.
```

배열 안에 인자를 받는 방법은 기존과 똑같다.

할당된 배열을 삭제해줄 때는 `delete[]`를 통해서 해체하면 된다.

```cpp
delete[] list;
```
