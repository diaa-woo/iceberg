[상위 문서로 이동](../../concept/struct.md)

# struct 예제 소개

## 1. C++에서 구조체 변수 선언 - typedef 불필요

```c++
#include <iostream>

using namespace std;

#define ID_LEN      20
#define MAX_SPD     200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10

struct Car 
{
    char gamerID[ID_LEN];
    int fuelGuage;
    int curSpeed;
};

void showCartState(const Car& car)
{
    cout << "User ID: " << car.gamerID << endl;
    cout << "Fuel Guage: " << car.fuelGuage << "%" << endl;
    cout << "Current Speed: " << car.curSpeed << "km/h" << endl << endl;
}

void accel(Car& car) 
{
    if(car.fuelGuage <= 0)
        return;
    else
        car.fuelGuage -= FUEL_STEP;

    if(car.curSpeed + ACC_STEP >= MAX_SPD)
    {
        car.curSpeed = MAX_SPD;
        return;
    }
    car.curSpeed += ACC_STEP;
}

void brake(Car& car) 
{   
    if(car.curSpeed < BRK_STEP)
    {
        car.curSpeed = 0;
        return;
    }

    car.curSpeed -= BRK_STEP;
}

int main(void) 
{
    Car run99 = { "run99", 100, 0 };    // Typedef를 쓰지 않았음에도 구조체를 선언하여 사용할 수 있음
    accel(run99);
    accel(run99);
    showCartState(run99);
    brake(run99);
    showCartState(run99);

    Car sped77 = {"sped77", 100, 0};
    accel(sped77);
    brake(sped77);
    showCartState(sped77);

    return 0;
}
```

## 2. 구조체 내부에 함수 삽입.

구조체 내에서 선언된 함수들은 모두 `inline`으로 처리된다. 또한 한 구조체 내에서 처리하는 것이기에 따로 구조체를 불러올 필요는 없다.

```C++
#include <iostream>

using namespace std;

#define ID_LEN      20
#define MAX_SPD     200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10

struct Car 
{
    char gamerID[ID_LEN];
    int fuelGuage;
    int curSpeed;

    void showCartState()
    {
        cout << "User ID: " << gamerID << endl;
        cout << "Fuel Guage: " << fuelGuage << "%" << endl;
        cout << "Current Speed: " << curSpeed << "km/h" << endl << endl;
    }

    void accel() 
    {
        if(fuelGuage <= 0)
            return;
        else
            fuelGuage -= FUEL_STEP;

        if(curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }
        curSpeed += ACC_STEP;
    }

    void brake() 
    {   
        if(curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
    }
};

int main(void) 
{
    Car run99 = { "run99", 100, 0 };
    run99.accel();
    run99.accel();
    run99.showCartState();
    run99.brake();
    run99.showCartState();

    Car sped77 = {"sped77", 100, 0};
    sped77.accel();
    sped77.brake();
    sped77.showCartState();

    return 0;
}
```

## 3. 구조체 안에 enum 상수 선언

```C++
#include <iostream>

using namespace std;

struct Car 
{
    enum        // Define 부분을 enum화 시켰다.
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };

    char gamerID[ID_LEN];
    int fuelGuage;
    int curSpeed;

    void showCartState()
    {
        cout << "User ID: " << gamerID << endl;
        cout << "Fuel Guage: " << fuelGuage << "%" << endl;
        cout << "Current Speed: " << curSpeed << "km/h" << endl << endl;
    }

    void accel() 
    {
        if(fuelGuage <= 0)
            return;
        else
            fuelGuage -= FUEL_STEP;

        if(curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }
        curSpeed += ACC_STEP;
    }

    void brake() 
    {   
        if(curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
    }
};

int main(void) 
{
    Car run99 = { "run99", 100, 0 };
    run99.accel();
    run99.accel();
    run99.showCartState();
    run99.brake();
    run99.showCartState();

    Car sped77 = {"sped77", 100, 0};
    sped77.accel();
    sped77.brake();
    sped77.showCartState();

    return 0;
}
```

## 4. 외부 정의 가능한 함수(Inline으로 처리하지 않음!)

```c++
#include <iostream>

using namespace std;

struct Car
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };

    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState();
    void Accel();
    void Break();
};

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재 속도: " << curSpeed << "km/h" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= FUEL_STEP;

    if (curSpeed + ACC_STEP >= MAX_SPD)
    {
        curSpeed = MAX_SPD;
        return;
    }
    curSpeed += ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_STEP;
}



int main(void)
{
    Car run99 = { "run99", 100, 0 };
    run99.Accel(); // run99의 맴버 함수
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77 = { "sped77", 100, 0 };
    sped77.Accel();  // sped77의 맴버 함수
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}
```

struct를 하나의 namespace로 취급하여 Car의 멤버 변수를 상속받는 함수를 만들어줄 수 있음

## 5. 명시적 Inline 실행

```C++
#include <iostream>

using namespace std;

struct Car
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };

    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    inline void ShowCarState();     // 명시적 inline 이용
    inline void Accel();
    inline void Break();
};

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재 속도: " << curSpeed << "km/h" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= FUEL_STEP;

    if (curSpeed + ACC_STEP >= MAX_SPD)
    {
        curSpeed = MAX_SPD;
        return;
    }
    curSpeed += ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_STEP;
}



int main(void)
{
    Car run99 = { "run99", 100, 0 };
    run99.Accel(); // run99의 맴버 함수
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77 = { "sped77", 100, 0 };
    sped77.Accel();  // sped77의 맴버 함수
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}
```