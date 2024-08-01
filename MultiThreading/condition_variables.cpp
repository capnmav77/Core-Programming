#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>


std::mutex mu;
std::condition_variable cv;
bool ready =false;

void waitforsignal(){
    std::unique_lock<std::mutex> lock(mu);
    cv.wait(lock, []{return ready;});
    std::cout<<"received signal"<<std::endl;
}

void signal(){
    // used to notify the waiting thread that the condition has been met and it can continue
    {
        std::lock_guard<std::mutex> lock(mu);
        ready = true;
    }
    cv.notify_one();
}



int main(){
    std::thread p1(waitforsignal);
    std::thread p2(signal);

    p1.join();
    p2.join();

    return 0;
}