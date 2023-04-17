#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main() {
    system_clock::time_point start_time = system_clock::now();  // 코드 시작 시간

    cout << "안녕!" << "뭐라는거야 ㅡㅡ" <<endl;

    system_clock::time_point end_time = system_clock::now();

    /* 시간 계산 (종료 - 시작) */
    nanoseconds nano = end_time - start_time;
    microseconds micro = duration_cast<microseconds>(end_time - start_time);
    milliseconds mill = duration_cast<seconds>(end_time - start_time);
    seconds sec = duration_cast<seconds>(end_time - start_time);
    minutes min = duration_cast<minutes>(end_time - start_time);
    hours hour = duration_cast<hours>(end_time - start_time);

    cout << "걸린 시간 : " << nano.count() << "nanoseconds" << endl;
    cout << "걸린 시간 : " << micro.count() << "microseconds" << endl;
    cout << "걸린 시간 : " << mill.count() << "milliseconds" << endl;
    cout << "걸린 시간 : " << sec.count() << "seconds" << endl;
    cout << "걸린 시간 : " << min.count() << "minutes" << endl;
    cout << "걸린 시간 : " << hour.count() << "hour" << endl;

    return 0;
}