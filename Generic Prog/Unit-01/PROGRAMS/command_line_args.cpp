#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>



int main(int argc , char* argv[] , char** env)
{
    char **ptr = env;
    while(ptr){
        std::cout<<*ptr<<std::endl;
        ptr++;
    }

    return 0;
}