#include<iostream>
#include<thread>
#include<mutex>

std::mutex mu; 
int shared_data =0 ;


void increment(){
    //check for the lock and unlock
    std::lock_guard<std::mutex> lock(mu); // this lock will be released when the function goes out of scope
    shared_data++;
    std::cout<<"shared data: "<<shared_data<<std::endl;
    return ;
}

int main(){
    std::thread p1(increment);
    std::thread p2(increment);

    p1.join();
    p2.join();

    std::cout<<"shared data: "<<shared_data<<std::endl;
    return 0;

}

// RAII principle: Resource Acquisition Is Initialization - is a programming idiom used in several object-oriented languages like C++, D, Ada and Vala that is used to manage resources in a safe way. The technique was developed to improve exception safety and to reduce the complexity of code.