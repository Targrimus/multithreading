#include <iostream>
#include <iomanip>
#include <future>
#include <thread>
#include <cmath>
#include <exception>

using namespace std;

double calculate_pi(int iter){

    if (iter <= 0) throw runtime_error("argument can not be less then 1\n");
    
    double sum = 0.0;

    for (size_t i = 0; i < iter; i++)
    {
        sum += pow(-1,i)*1/(2*i+1);
    }

    return sum*4;   
}



int main(int argc, char ** argv){

    packaged_task<double(int)> task1(calculate_pi);
    future<double> f1 = task1.get_future();

    thread t1(move(task1), 0);

    try
    {
        cout << setprecision(15) << f1.get() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    

    t1.join();

return 0;
}