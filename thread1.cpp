#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <mutex>

using namespace std;


double calc_pi(int times){
    double result;
    for(double i = 1; i <= times; i++){
        result += pow(-1,i)*-1/(2*i-1);
    }
    return result*4;
}


int main () {



thread t1([](){
    auto start = chrono::steady_clock::now();
    cout << setprecision(15);
    cout << calc_pi(1E8) << "\n";
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "T1 runs in " << elapsed_seconds.count() << " seconds" << endl;
});

thread t2([](){
    auto start = chrono::steady_clock::now();
    cout << setprecision(15);
    cout << calc_pi(1E8) << "\n";
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "T2 runs in " << elapsed_seconds.count() << " seconds" << endl;
});

thread t3([](){
    auto start = chrono::steady_clock::now();
    cout << setprecision(15);
    cout << calc_pi(1E8) << "\n";
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "T3 runs in " << elapsed_seconds.count() << " seconds" << endl;
});

thread t4([](){
    auto start = chrono::steady_clock::now();
    cout << setprecision(15);
    cout << calc_pi(1E7) << "\n";
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "T4 runs in " << elapsed_seconds.count() << " seconds" << endl;
});

t1.join();
t2.join();
t3.join();
t4.join();





return 1;
}