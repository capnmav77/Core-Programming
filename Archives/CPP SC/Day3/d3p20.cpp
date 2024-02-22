#include <iostream>

class IntArray {
    int* arr;
    int size;

public:
    // Constructor
    IntArray(int s) : size(s) {
        arr = new int[s];
    }

    // Destructor
    ~IntArray() {
        delete[] arr;
    }

    // Overloading the '[]' operator
    int& operator[](int index) {
        if (index >= size) {
            std::cout << "Array index out of bound.\n";
            exit(0);
        }

        // Return reference so that we can change the value in array
        return arr[index];
    }
};

int main() {
    IntArray a(10);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "a[2] = " << a[2] << std::endl;

    return 0;
}
