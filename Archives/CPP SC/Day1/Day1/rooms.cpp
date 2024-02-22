// Program to illustrate the working of objects and class in C++ Programming

#include <iostream>
using namespace std;

// Define a class
class Room {

   public:
    double length;
    double breadth;
    double height;

    double calculateArea() {
        return length * breadth;
    }

    double calculateVolume() {
        return length * breadth * height;
    }
};

int main() {

    // create object of Room class
    Room room1;

    cout << "Key in the values for length breadth and height of the room" << endl;
    cin >> room1.length >> room1.breadth >> room1.height;

    // calculate and display the area and volume of the room
    cout << "Area of Room =  " << room1.calculateArea() << endl;
    cout << "Volume of Room =  " << room1.calculateVolume() << endl;

    return 0;
}
