[상위 문서로 이동](../README.md)

# 구조체

C++에서는 고유한 사용자 정의 집계 데이터 유형(*user-defined aggergate data type*) 생성할 수 있는데, 여기서 **집계 데이터 유형(aggergate data type)**은 여러 개별 변수를 함께 그룹화하는 데이터 유형이다. 가장 단순한 집계 데이터 유형 중 하나는 **구조체(struct)**이다.

즉, **구조체(struct)는 하나 이상의 변수를 그룹 지어서 새로운 자료형을 정의하는 것**이다.

## 구조체 선언 및 정의 (Declaring and defining structs)

```C++
struct Employee     // 대문자로 시작하여 변수 이름과 구분
{
    short id;
    int age;
    double wage;
};      // 꼭 새미콜론 넣어주기!
```

구조체 이름을 설정하고 안에 변수를 넣어주어 구조체를 선언한다. 이러한 변수를 **멤버(member) or 필드(field)**라고 한다.

현재 `Employee` 구조체는 단지 선언에 불과하다. 즉, 현재는 어떤 메모리도 할당되지 않다.

구조체를 할당받아 사용하려면 `Employee` 타입의 변수를 선언하면 된다.

```C++
Employee joe;
```

## 구조체 멤버 접근 (Accessing Struct Members)

개별 멤버에 접근하기 위해 **멤버 선택 연산자(memeber selection operator: `.`)**를 사용하면 된다.

```C++
Employee joe; 
joe.id = 14;  
joe.age = 32;      
joe.wage = 24.15;  

Employee frank;    
frank.id = 15;     
frank.age = 28;    
frank.wage = 18.27;
```

일반 변수처럼 구조체 멤버 변수도 초기화되지 않고 쓰레기 값이 들어간다. 그러므로 수동으로 초기화해야 한다.

구조체 멤버 변수는 일반 변수와 같게 작용한다.

## 구조체 초기화 (Initializing Structs)

멤버별로 값을 지정하여 구조체를 초기화하는 작업은 매우 번거로우므로 C++은 **초기화 목록(Initializer List)**을 사용하여 구조체를 초기화하는 더 빠른 방법을 지원한다. 이렇게 하면 선언 시간에 구조체의 일부 도는 전체 멤버 변수를 초기화 할 수 있다.

```C++
Employee joe { 1, 32, 60000.0 }; 
Employee frank { 2, 28 };
```

유니폼 초기화(Uniorm Initalization)이라고도 한다.

만일 초기화 목록에 일부 멤버의 초기값이 포함되어 있지 않으면 해당 멤버는 기본(default)값으로 초기화된다. 

## Non-static Member Initialization

비정적(non-static) 멤버 변수에 기본값을 지정할 수 있다.

```C++
struct Rectangle
{
    double length = 1.0;
    double width  = 1.0;
};

int main()
{
    Rectangle x;   // length = 1.0, width = 1.0

    x.length = 2.0; // you can assign other values like normal

    return 0;
}
```

C++11에서는 일부 제한이 있지만, C++14부터는 이 제한이 모두 풀렸다고 한다. 따라서 초기화 목록/유니폼 초기화를 둘 다 사용할 수 있다. 우선 순위는 초기화 목록부터.

## 구조체와 함수 (Structs and Functions)

구조체를 멤버와 함께 함수에 전달 할 수 있다는 건 상당히 큰 장점이다.

```C++
void printInformation(Employee employee)
{
    std::cout << "ID:   " << employee.id << "\n";
    std::cout << "Age:  " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
}
```

또한, 함수는 구조체를 반환함으로써 **여러 변수를 반환할 수 있다.**

```C++
struct Point3d
{
    double x;
    double y;
    double z;
};

Point3d getZeroPoint()
{
    Point3d temp = { 0.0, 0.0, 0.0 };
    return temp;
}
```

## 중첩된 구조체 (Nested Structs)

구조체는 다른 구조체를 포함할 수 있다.

```C++
struct Employee
{
    short id;
    int age;
    double wage;
};

struct Company
{
    Employee CEO; 
    int numberOfEmployees;
};

Company myCompany;
```

위 프로그램에서 `CEO`의 월급을 알고 싶으면 **멤버 선택 연산자(member selection operator: `.`)를 두 번 사용하면 된다.

```C++
std::cout << myCompany.CEO.wage << std::endl;
```

중첩된 구조체에 대해 중첩된 초기화 목록을 사용할 수 있다.

```C++
Company myCompany = {{ 1, 42, 60000.0f }, 5 };
```

## 구조체 크기와 정렬 (Struct size and data Structure Alignment)

일반적으로 구조체의 크기는 **모든 멤버의 크기를 합한 것**이다. 하지만 항상 예외는 존재하는 법.

위 `Employee` 구조체의 총 크기는 2 + 4 + 8 이므로 14바이트를 예상할 수 있다. 하지만 `sizeof()`함수를 사용하면 *16바이트*라고 출력한다. 

이 이유는 성능상의 이유로 컴파일러는 때때로 구조에 간격을 추가하는 데, 이를 **패딩(padding)**이라고 한다.

해당 문제는 메모리와 관련되어 있는데, 자세한 내용은 패딩 참조

# 예제

[example](../code/struct/example_guide.md)


## 참고
https://boycoding.tistory.com/183
https://wikidocs.net/14028