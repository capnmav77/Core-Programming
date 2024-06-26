// Program to demonstrate arrays
    
#include <iostream>
    #include <array>

    using namespace std;

    int main()
    {
        // creating an array
        array<int, 5> arr = {10, 11, 12, 12, 13};

        // creating an iterator for the array
        array<int, 5>::iterator it;

        // iterating through each element of the array using the iterator
        cout << "The array is: ";
        for(it = arr.begin(); it < arr.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;

        cout << "Size of the array is: " << arr.size() << endl;

        return 0;
    }
