#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
    // Initialzing a vector v1.
    vector<int> v1 = {1, 2, 6, 8, 3, 7, 9, 5, 4};

/*
Performing the sorting, by default, the sort() function returns the elements in ascending order. Hence to sort the elements in descending order, we use a predefined functor, "greater".
*/
    sort(v1.begin(), v1.end(), greater < int > ());

    // Printing the values.
    for (int num: v1) {
        cout << num << " ";
    }

    return 0;
}
