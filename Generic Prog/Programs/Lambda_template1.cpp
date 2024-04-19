#include <iostream>
#include <vector>
// using namespace std;

auto l3 = []<typename T>(std::vector<T>& vec){ 
              //do your stuff with std::vector<T>
           };
int main(){
    std::vector<int> vec1{1,2,3,4,5,6,7,8,9};
    std::vector<float> vec2{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    l3(vec1);
    l3(vec2);
}