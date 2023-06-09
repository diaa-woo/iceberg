# 인라인 함수(Inline Function)

## 함수에 대하여

- 함수 내부 코드 재사용성 증대
- 인스턴스 코드보다 함수에서 코드를 변경하거나 업데이트하기 더 쉬움
- 함수 이름을 통해 코드 파악 쉬움
- 함수 호출 인수가 함수 매개 변수와 일치하는지 자동으로 타입 검사 진행(매크로 진행X)
- 프로그램 디버그가 더 쉬움

그러나 함수는 호출될 때마다 발생하는 일정량의 성능 오버헤드가 있다는 단점이 존재함. 이는 CPU가 다른 Register와 함께 실행 중인 현재 명령어의 주소를 저장해야 하므로(나중에 반환할 위치를 알기 위해)모든 함수 매개 변수를 생성해야 하는데, 할당된 값을 사용하면 프로그램이 새 위치로 분기됨. 이는 컴퓨터 성능 저하로 이어질 수 있음

크기나 복잡한 Task를 수행하는 함수의 경우에는 이 오버헤드는 그닥 중요한 내용은 아님. 하지만 일반적으로 사용하는 작은 함수의 경우, 함수 호출에 필요한 시간이 실제로 함수 코드를 실행하는 데 필요한 시간보다 훨씬 많은 경우가 있음.

## Inline Function이란?

C++은 위 문제를 보완해주기 위해 **인라인 함수(Inline Function)** 이라는 내부에서 작성된 코드의 속도와 함수의 장점을 결합하는 방법을 제공한다. `inline` 키워드는 컴파일러에서 함수를 인라인 함수로 처리하도록 요쳥하는데, 컴파일러가 코드를 컴파일하면 모든 인라인 함수가 인-플레이스(in-place) 확장된다. 즉, 함수 호출이 함수 자체의 내용 복사본으로 대체되어 함수 오버헤드가 제거된다!

다만 단점은 인라인 함수가 모든 함수 호출에 대해 적절한 위치에서 확정되므로 인라인 함수가 길거나 여러 번 호출하는 경우 컴파일된 코드를 약간 더 크게 만들 수 있다

정리하자면, 짧게 반복해야 하는 구문들은 인라인 함수를 쓸 시 상당한 효율을 낼 수 있다는 것이다.

```C++
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int min(int x, int y) {
    return x > y ? y : x;
}

inline int min(int x, int y, int z)  // Seperate Variable  
{
    return x > y ? y : x;
}

int main() {
    cout << "General Function : ";
    system_clock::time_point start_time = system_clock::now();
    cout << min(5, 6);  //general
    system_clock::time_point end_time = system_clock::now();
    
    microseconds mill = duration_cast<microseconds>(end_time - start_time);
    cout << " Take time: " << mill.count() << '\n';

    cout << "Inline Function : ";
    start_time = system_clock::now();
    cout << min(3, 2);  //inline
    end_time = system_clock::now();

    mill = duration_cast<microseconds>(end_time - start_time);
    cout << " Take time: " << mill.count() << '\n';

    return 0;
}
```

해당 코드를 돌려보면 inline이 더 빠른 걸 알 수 있다. 좀 더 세밀하게 들여다보면 그냥 다음과 같다.

```C++
int main()
{
    std::cout << (5 > 6 ? 6 : 5) << '\n';
    std::cout << (3 > 2 ? 2 : 3) << '\n';
    return 0;
}
```

`min()` 함수가 있던 자리에 그냥 함수에 있는 코드를 집어넣은 격이랑 똑같다.