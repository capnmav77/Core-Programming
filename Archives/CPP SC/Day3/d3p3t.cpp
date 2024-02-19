// See this 
class MyClass {
private:
    int data;
public:
    MyClass(int value) : data(value) {}

    friend void friendFunc(MyClass& obj);
};

void friendFunc(MyClass& obj) {
    // Code to call the destructor of MyClass
   // Is it possible? Why would you want to do this
}
