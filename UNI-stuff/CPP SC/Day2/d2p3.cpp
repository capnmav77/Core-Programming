// A singleton class
class Singleton {
private:
    // A static pointer to the single instance
    static Singleton* instance;

    // A private constructor
    Singleton() {
        // Initialize the instance
    }

public:
    // A public static method to get the single instance
    static Singleton* getInstance() {
        // Create the instance if it does not exist
        if (instance == nullptr) {
            instance = new Singleton();
        }
        // Return the instance
        return instance;
    }

    // Other public methods of the class
};
