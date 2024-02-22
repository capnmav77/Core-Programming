#include <iostream>
using namespace std;

namespace outer_ns 
{   
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;
    
    namespace inner_ns 
    {
        // Creating a function inside the inner namespace.
        void printer(int arr[], int len) 
        {
            for (int i = 0; i < len; i++) {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
        }
    }

    void print_5_integers() 
    {
        // Calling the printer() function from inner namespace.
        inner_ns::printer(arr, len);
    }
}

int main() 
{
    int numbers[] = {10, 20, 30};
    
    // Printing the elements of the numbers array.
    outer_ns::inner_ns::printer(numbers, 3);
    
    // Executing the print_5_integers function.
    outer_ns::print_5_integers();
    
    return 0;
}
