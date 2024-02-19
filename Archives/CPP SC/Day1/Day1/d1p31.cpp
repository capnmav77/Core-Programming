#include <iostream>

// Engine class
class Engine {
public:
    void start() {
        std::cout << "Engine started." << std::endl;
    }
};

// Car class
class Car {
private:
    Engine engine; // Car has-a Engine. This is composition.

public:
    void start() {
        engine.start(); // delegate the start behavior to the engine
        std::cout << "Car started." << std::endl;
    }
};

int main() {
    Car car;
    car.start(); // Outputs: Engine started. Car started.
    return 0;
}
