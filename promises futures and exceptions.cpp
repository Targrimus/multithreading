#include <iostream>
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
        sum += pow(-1,i)*1/(2*i-1);
    }

    return sum*4;   
}



int main(int argc, char ** argv){

promise<double> p1;

auto do_calc = [&](int terms){
    

    try
    {    
        double result = calculate_pi(terms);
        p1.set_value(result);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        p1.set_exception(current_exception());
    }
    
};

thread t1(do_calc, 0);

future<double> f1 = p1.get_future();

cout << f1.get() << endl;

t1.join();


return 0;
}