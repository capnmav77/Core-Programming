#include<iostream>
#include<future>
#include<thread>

void setPromise(std::promise<int> &&p){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_value(42);
}


int main(){
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread p1(setPromise,std::move(prom));

    std::cout<<"waiting for the value"<<std::endl;
    std::cout<<"value: "<<fut.get()<<std::endl;
    p1.join();
    return 0;
}