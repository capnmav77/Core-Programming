#include<iostream>

template <typename T, int size>
class StaticArray{
        T m_array[size]{};
    public:
        T* getArray();

        T &operator[](int index)
        {
            return m_array[index];
        }
};


template<typename T,int size> 
T* StaticArray<T,size>:: getArray()
{
    return m_array;
}

int main()
{
    StaticArray<int,12> int_array;

    for(int count=0;count<12;++count)
    int_array[count] = count;

    for(int count=11;count>=0;--count)
    std::cout<<int_array[count]<<std::endl;


}
