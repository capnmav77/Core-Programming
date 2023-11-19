// declare a function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

// declare another function with the same name but different parameters
// this function takes three integers and returns their sum
int add(int a, int b, int c) {
    return a + b + c;
}

int main()
{
    // call the first function with two arguments
    cout << add(10, 20) << endl; // output: 30

    // call the second function with three arguments
    cout << add(10, 20, 30) << endl; // output: 60

    return 0;
}
