#include<iostream>
#include<vector>

template<typename T>
bool is_sorted(T first , T last){
    if(first == last) return true;

    T next = first;
    while(++next != last){
        if(*next <* first) return false ; 
        first = next;
    }
    return true;
}


int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::string s = "Helloworld";
    std::cout<<is_sorted<std::vector<int>::iterator>(v.begin(),v.end());
    //std::cout<<is_sorted<std::string::iterator>(s.begin(),s.end());
    return 0;
}