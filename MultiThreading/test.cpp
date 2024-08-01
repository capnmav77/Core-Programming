#include<iostream>
#include<thread>

using namespace std::literals::chrono_literals;

static bool is_finished = false;

void DoWork(){

    std::cout<<"thread id"<<std::this_thread::get_id()<<std::endl;
    while(!is_finished){
        std::cout<<"working ..."<<std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread worker(DoWork);

    std::cin.get();
    is_finished = true;
    worker.join();

    std::cin.get();

    std::cout<<"thread id"<<std::this_thread::get_id()<<std::endl;


    std::cout<<"finished"<<std::endl;
    
}