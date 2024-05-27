#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<concepts>  

// 1.a. Write a template function called printType that prints the type of the given
// input. Specialize this template function for int, float, and double types to print a
// custom message for each type

// template<typename T>
// void printType(T t) {
//     std::cout << "the type of this variable is : " << typeid(t).name() << std::endl;
// }

// // Explicit specialization for int
// template<>
// void printType(int t) {
//     std::cout << "the type of this variable is : int" << std::endl;
// }

// // Explicit specialization for float
// template<>
// void printType(float t) {
//     std::cout << "the type of this variable is : float" << std::endl;
// }

// // Explicit specialization for double
// template<>
// void printType(double t) {
//     std::cout << "the type of this variable is : double" << std::endl;
// }

// int main() {
//     int intValue = 10;
//     float floatValue = 3.14f;
//     double doubleValue = 2.71828;

//     printType(intValue);      // Prints: the type of this variable is : int
//     printType(floatValue);    // Prints: the type of this variable is : float
//     printType(doubleValue);   // Prints: the type of this variable is : double

//     return 0;
// }


// 1.b. Create a template function called identityMatrix that returns an identity matrix
// (a square matrix with 1s on the diagonal and 0s elsewhere) of the given size. Use a
// non-type template parameter to specify the size of the matrix.
// template<int N>
// std::vector<std::vector<int>> identityMatrix() {
//     std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));
//     for (int i = 0; i < N; i++) {
//         matrix[i][i] = 1;
//     }
//     return matrix;
// }

// int main() {
//     auto matrix = identityMatrix<4>();
//     for (int i = 0; i < matrix.size(); i++) {
//         for (int j = 0; j < matrix[0].size(); j++) {
//             std::cout << matrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }

// 1.c. Write a template function named sumArray that calculates the sum of
// elements in an array. Use explicit instantiation to demonstrate the usage -
// meaning use this function - of this function with at least two different data types

// template <typename T> 
// int sumArray(T arr[], int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//     }
//     return sum;
// }

// template int sumArray<int>(int arr[], int n);
// template int sumArray<float>(float arr[], int n);   

// int main(){
//     int arr1[] = {1, 2, 3, 4, 5};
//     float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

//     std::cout << "Sum of arr1: " << sumArray(arr1, 5) << std::endl;
//     std::cout << "Sum of arr2: " << sumArray(arr2, 5) << std::endl;

//     return 0;
// }

// 1.d. Implement a template function called compareArrays that compares two
// arrays of the same type and size for equality. Use both type and non-type template
// parameters to define this function.

// template<typename T , size_t N>
// bool compareArrays(T (&arr1)[N], T (&arr2)[N]) {
//     for (int i = 0; i < N; i++) {
//         if (arr1[i] != arr2[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int arr1[] = { 1,2,3,4,5};
//     int arr2[] = {1,2,3,4,5};
//     cout<<compareArrays(arr1, arr2)<<endl;
//     return 0;
// }

// 2.a. Create a generic Base template class with a single member function called
// getName that returns a string representing the class name. Then, create a derived
// template class Derived that inherits from Base and overrides the getName function
// to return its own class name. Demonstrate the usage of both classes.

// template< typename T> 
// class Base{
//     public: 
//     virtual void getName(string s){
//         cout<<"Base"<<s<<endl;
//     }
// };

// template <typename T>
// class Derived : public Base<T>{
//     public :
//     void getName(string s) override{
//         cout<<"Derived"<<s<<endl;
//     }
// };

// int main(){
//     Base<string> B;
//     Derived<string> D;
//     B.getName("Base");
//     D.getName("Derived");
//     return 0;
// }

// b. Design a template class Pair that stores two values of different types.
// Implement a member function called sum that returns the sum of the two values
// for numeric types.

// template<typename T , typename U>
// class Pair{
//     public : 
//     T a;
//     U b;
//     Pair(T a, U b){
//         this->a = a;
//         this->b = b;
//     }
//     decltype(a+b) sum (){
//         if(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value){
//             return a+b;
//         }
//         else{
//             cout<<"Not a numeric type"<<endl;
//         }
//     }

// };

// int main(){
//     Pair<int, float> p(1, 2.5);
//     cout<<p.sum()<<endl;
//     return 0;
// }   


// 2.c. Create a template class Container that stores a single value of any type.
// Implement a template friend function swapContents that swaps the contents of
// two Container objects. Demonstrate the usage of the swapContents function. Use
// std::swap. Dont write your own function :


// template<typename T> // Forward declaration of Container template
// class Container;

// template<typename T> // Forward declaration of swapContents template function
// void swapContents(Container<T>& t1, Container<T>& t2);

// template<typename U> // Forward declaration of displayContainerValues template function
// void displayContainerValues(Container<U>& t1, Container<U>& t2);

// template<typename T>
// class Container{
//     private: 
//     T value;
//     public: 
//     Container(T value){
//         this->value = value;
//     }

//     // Declaring friend function swapContents
//     friend void swapContents<T>(Container<T>& t1, Container<T>& t2);

//     // Declaring friend function displayContainerValues
//     template<typename U>
//     friend void displayContainerValues(Container<U>& t1, Container<U>& t2);
// };

// template<typename T>
// void swapContents(Container<T>& t1, Container<T>& t2){
//     std::swap(t1.value, t2.value);
// }

// template<typename U>
// void displayContainerValues(Container<U>& t1, Container<U>& t2){
//     std::cout << t1.value << std::endl;
//     std::cout << t2.value << std::endl;
// }

//alternate 
// template<typename T>
// class Container{
//     private:
//     T value;
//     public:
//     Container(T value){
//         this->value = value;
//     }
//     template<typename U>    
//     friend void swapContents(U &, U &);
//     template<typename U>
//     friend void displayContainerValues(U, U);
// };

// template<typename U>
// void swapContents(U &t1, U &t2){
//     std::swap(t1.value, t2.value);
// }

// template<typename U>
// void displayContainerValues(U t1, U t2){
//     std::cout << t1.value << std::endl;
//     std::cout << t2.value << std::endl;
// }

// int main(){
//     Container<int> c1(20);
//     Container<int> c2(30);
//     swapContents(c1, c2);
//     displayContainerValues(c1, c2);
//     return 0;
// }


// 2.d. Implement a template class Matrix that stores a 2D matrix of any numeric
// type. Inside the Matrix class, define a nested template class RowProxy that
// represents a single row of the matrix and provides an overloaded operator[] for
// element access. Show the usage of the Matrix class and its nested RowProxy. Use
// std::vector if you wish.


// template<typename T >
// concept Numeric = std::is_arithmetic<T>::value;

// template <typename N>
// class Matrix{
//     private:
//     std::vector<std::vector<N>> matrix;

//     public:
//     Matrix(int rows, int cols){
//         matrix.resize(rows, std::vector<N>(cols));
//     }

//     class RowProxy{
//         private : 
//         std::vector<N>& row;
//         public : 
//         RowProxy(std::vector<N>& row): row(row){}
//         N& operator[](int index){ //overloading [] operator
//             return row[index];
//         }

//     };

//     RowProxy operator[](int index){
//         return RowProxy(matrix[index]);
//     }

//     void display(){
//         for(int i = 0; i < matrix.size(); i++){
//             for(int j = 0; j < matrix[0].size(); j++){
//                 std::cout << matrix[i][j] << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
// };

// int main(){
//     Matrix<int> m(3, 3);
//     m[0][0] = 1;
//     m[0][1] = 2;
//     m[0][2] = 3;
//     m[1][0] = 4;
//     m[1][1] = 5;
//     m[1][2] = 6;
//     m[2][0] = 7;
//     m[2][1] = 8;
//     m[2][2] = 9;

//     m.display();

//     return 0;
// }

// 3.a. Write a C++ program that demonstrates the usage of std::vector, std::list, and
// std::map. Perform basic operations such as adding elements, removing elements,
// and accessing elements for each container.

// template<typename T> 
// class Vector{
//     private : 
//     vector<T> arr;
//     int size = 0;
//     public :
//     void push_back(T element){
//         arr.push_back(element);
//         size++;
//     }
//     void pop_back(){
//         arr.pop_back();
//         size--;
//     }
//     T operator[](int index){
//         return arr[index];
//     }

//     int Size(){
//         return size;
//     }   
// };


// template <typename T> 
// class List{
//     private : 
//     list<T> arr;
//     int size = 0;
//     public :
//     void push_back(T element){
//         arr.push_back(element);
//         size++;
//     }

//     void pop_back(){
//         arr.pop_back();
//         size--;
//     }

//     void push_front(T element){
//         arr.push_front(element);
//         size++;
//     }

//     void pop_front(){
//         arr.pop_front();
//         size--;
//     }

//     void display(){
//         for(auto i : arr){
//             cout<<i<<" ";
//         }
//         cout<<endl;
    
//     }
// };

// template <typename T, typename U> 
// class Map{
//     private : 
//     map<T, U> mapp;
//     int size = 0;
//     public :
//     void insert(T key, U value){
//         mapp.insert({key, value});
//         size++;
//     }

//     void erase(T key){
//         mapp.erase(key);
//         size--;
//     }

//     void display(){
//         for(auto i : mapp){
//             cout<<i.first<<" "<<i.second<<endl;
//         }
//     }
// };

// int main(){
//     // Vector<int> v;
//     // v.push_back(1);
//     // v.push_back(2);
//     // v.push_back(3);
//     // v.push_back(4);
//     // v.push_back(5);
//     // v.pop_back();
//     // for(int i = 0; i < v.Size(); i++){
//     //     cout<<v[i]<<" ";
//     // }

//     // List<int> l;
//     // l.push_back(1);
//     // l.push_back(2);
//     // l.push_back(3);
//     // l.display();
//     // l.pop_back();
//     // l.display();
//     // l.push_front(9);
//     // l.display();
//     // l.pop_front();
//     // l.display();

//     // Map<int, string> m;
//     // m.insert(1, "one");
//     // m.insert(2, "two");
//     // m.insert(3, "three");
//     // m.display();
//     // m.erase(2);
//     // m.display();


//     return 0;
// }


// 3.b. Using the C++ Standard Template Library (STL), write a program that reads a
// sequence of numbers from the user, stores them in a container, and then sorts
// and prints the numbers in ascending order. Use std sort functions if you wish 


// class container{
//     private :
//     vector<int> arr;
//     public :
//     void insert(int element){
//         arr.push_back(element);
//     }
//     void insertvector(vector<int> v){
//         for(auto i : v){
//             arr.push_back(i);
//         }
//     }

//     void sort(){
//         std::sort(arr.begin(), arr.end());
//     }

//     void sort_rev(){
//         std::sort(arr.begin(),arr.end(),greater<int>());
//     }

//     void display(){
//         for(auto i : arr){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }   
// };
// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};
//     container c;
//     c.insertvector(arr);
//     c.display();
//     c.sort();
//     c.display();
//     c.sort_rev();
//     c.display();
//     return 0;
// }

// 3.c. Explain the concept of an iterator in C++ STL and write a program that
// demonstrates the usage of forward, bidirectional, and random-access iterators
// with suitable containers.

// an iterator is a pointer like object that points to an element in a container. It is used to iterate over the elements of a container.
// example of forward iterator : for(vector<int>::iterator it = v.begin(); it != v.end(); it++
// example of bidirectional iterator: for(list<int>::iterator it = l.begin(); it != l.end(); it++
// example of random access iterator: for(vector<int>::iterator it = v.begin(); it != v.end(); it++

// template<typename T>
// class Iterator{
// public:    
//     vector<T> arr;

//     void insert(T element){
//         arr.push_back(element);
//     }
//     void insert(vector<T> v){
//         for(auto i : v){
//             arr.push_back(i);
//         }
//     }
// };

// template<typename T> 
// class ForwardIterator : public Iterator<T>{
// public: 
//     void display(){
//         for(auto i : this->arr){
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// };

// template<typename T>
// class BidirectionalIterator : public Iterator<T>{
// public: 
//     void display(){
//         for(auto i = this->arr.rbegin(); i != this->arr.rend(); i++){
//             cout << *i << " ";
//         }
//         cout << endl;
//     }
// };

// template<typename T>   
// class RandomAccessIterator : public Iterator<T>{
// public: 
//     void display(){
//         for(int i = 0; i < this->arr.size(); i++){
//             cout << this->arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};

//     // Create objects of iterator classes
//     ForwardIterator<int> forwardIter;
//     BidirectionalIterator<int> bidirectionalIter;
//     RandomAccessIterator<int> randomAccessIter;

//     // Insert elements into iterators
//     forwardIter.insert(arr);
//     bidirectionalIter.insert(arr);
//     randomAccessIter.insert(arr);

//     // Display elements using different iterators
//     cout << "Forward Iterator: ";
//     forwardIter.display();

//     cout << "Bidirectional Iterator: ";
//     bidirectionalIter.display();

//     cout << "Random Access Iterator: ";
//     randomAccessIter.display();

//     return 0;
// }

// 3.d. Describe the concept of traits in C++ and how they can be used in conjunction
// with STL algorithms. Write a program that demonstrates the usage of a custom
// trait for comparing two custom data types

// concepts are used to define constraints on template parameters. They are used to restrict the types that can be used as template arguments.
// type traits are used to query the properties of types at compile time. They are used to define the properties of types and to perform compile-time type introspection.
// there are methods to use concepts and type traits in conjunction with STL algorithms.

//ex : template <std::integral T>
// template<typename T>
// requires std::floating_point<T>
// we can also use tt : requires std::is_same_v<T, U>
// trailing return type : auto add(T a, U b) -> decltype(a+b)
// trailing requries clause : template<typename T> void func(T t) requires std::integral<T>
// abbreviated nested func : use std::integral auto x )


// template<typename T>
// concept Numeric = requires(T t){
//     {t + t} -> std::convertible_to<T>;
//     {X*X} -> std::same_as<T>;22


// template< typename T>
// concept Averagable = requires(T x, T y){
//     (x + y) / 2;
// };

// template<Averagable T>
// T Average(T x, T y){
//     return (x + y) / 2;
// }

// int main(void){
//     Average(3, 5);
//     std::string A{"Hello"};
//     std::string B{"World"};
//     Average(A, B);
//     return 0;
// }

// 4.b. Write a program that demonstrates the usage of C++ template
// metaprogramming to compute the factorial of a number at compile-time

// template<int N> 
// struct Factorial{
//     static const int value = N * Factorial<N-1>::value;
// };

// template<>
// struct Factorial<0>{
//     static const int value = 1;
// };

// int main(){
//     cout<<Factorial<5>::value<<endl;
//     return 0;
// }

