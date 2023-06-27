#if !defined(BLOCKING_QUEUE)
#define BLOCKING_QUEUE

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class BlockingQueue{
    std::condition_variable _cv;
    size_t _maxsize;
    std::queue<T> _queue;
    std::mutex _mtx;

public:
    BlockingQueue(size_t size=5):_maxsize(size){
    }

    void push(T item){
        std::unique_lock<std::mutex> lock(_mtx);
        _cv.wait(lock,[this](){return (_queue.size() < _maxsize);});
        _queue.push(item);
        std::cout << "push " << item << std::endl;
        lock.unlock();
        _cv.notify_one();
    }

    T pop(){
        std::unique_lock<std::mutex> lock(_mtx);
        _cv.wait(lock,[this](){return !_queue.empty();});

        T item = _queue.front();
        std::cout << "Pop " << item << std::endl;
        _queue.pop();

        lock.unlock();
        _cv.notify_one();
        return item;
    }

    size_t size() {
        std::unique_lock<std::mutex> lock(_mtx);
        std::cout << "size " << _queue.size() << std::endl;
        lock.unlock();
        return _queue.size();
    }



};



#endif // BLOCKING_QUEUE
