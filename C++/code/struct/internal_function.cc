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