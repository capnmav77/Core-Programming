#include<iostream>
#include<thread>
#include<future>
#include<vector>


void exex(int id){
    std::cout<<"starting thread "<<id<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"ending thread "<<id<<std::endl;
}

int main(){
    std::vector<std::future<void>> fu;
    for(int i=0 ; i<5 ; i++){
        fu.push_back(std::async(std::launch::async,exex,i));

    }
    for(auto &f : fu){
        f.get();
    }
    return 0;
}