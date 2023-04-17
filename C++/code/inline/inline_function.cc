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