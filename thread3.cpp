#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <exception>

using namespace std;


void func(mutex *mtx, int *counter, int sec, const char* name){
        for (size_t i = 0; i < 10; i++)
        {
                this_thread::sleep_for(chrono::seconds(sec));
                lock_guard<mutex> lg(*mtx);
                (*counter)++;
                cout << name << " thread updated counter " << *counter << endl;
        }
}


int main(int argc, char *argv[]) {

        mutex mtx;
        int counter = 0;

        thread th1(func, &mtx, &counter, 2, "A");
        thread th2(func, &mtx, &counter, 3, "B");

        th1.join();
        cout << "th1 done\n";

        th2.join();
        cout << "th2 done\n";






 

 return 0;
}