#include <iostream>
#include "BlockingQueue.h"
#include <thread>

int main(int argc, char ** argv){

BlockingQueue<int> qu(15);


std::thread t1([&](){
    for (size_t i = 0; i < 1E2; i++)
    {
        qu.push(i);
        qu.size();
    }
    
});

std::thread t2([&](){
    for (size_t i = 0; i < 1E2; i++)
    {
        qu.pop();
        qu.size();
    }
});

t1.join();
t2.join();

return 0;
}