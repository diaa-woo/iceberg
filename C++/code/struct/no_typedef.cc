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
    Car run99 = { "run99", 100, 0 };
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