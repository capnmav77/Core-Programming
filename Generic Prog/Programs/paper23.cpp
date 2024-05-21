// 1.a. Write a C++ template function called "printArray" that takes an array of any
// data type and its size as arguments. The function should print all the elements of
// the array. Demonstrate the usage of this function by printing an array of integers
// and an array of characters

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// template <typename T > 
// void printArray(T array,int  array_size){
//     for(int i=0 ; i<array_size ; i++){
//         cout<<array[i]<<" ";
//     }
// }


// int main()
// {
//     int arr[] = {1,2,3,4,5};
//     string arr2[] = {"a","b","c","d","e"};
//     printArray(arr,5);
//     printArray(arr2,5);
//     return 0;
// }

// 1.b. Implement a template function in C++ called "countOccurrences" that takes an
// array of any data type and its size, along with a target element. The function
// should return the number of times the target element occurs in the array. Test
// your function by counting the occurrences of an integer in an array of integers and
// a character in an array of characters.

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// template <typename T , typename U>
// int countOccurences (T array , int array_size , U target){
//     int occurences = 0;
//     for(int i=0 ; i<array_size ; i++){
//         if(array[i] == target){
//             occurences++;
//         }
//     }
//     return occurences;
// }


// int main()
// {
//     int iarr[] = {1,2,3,4,5};
//     int carr[] = {'a','b','c','d','e','a'};
//     cout<<countOccurences(iarr,5,3)<<endl;
//     cout<<countOccurences(carr,6,'a')<<endl;

//     return 0;
// }



// 1.c. Write a C++ template function called "sumEvenIndices" that takes an array of
// any numeric data type and its size as arguments. The function should calculate and
// return the sum of the elements at even indices (0, 2, 4, etc.) in the array. Test your
// function with an array of integers and an array of doubles

// #include<iostream>

// template <typename T, size_t N>
// T sumEvenIndices(T (&arr)[N]) {
//     T sum = 0;
//     for (size_t i = 0; i < N; i += 2) {
//         sum += arr[i];
//     }
//     return sum;
// }


// int main()
// {
//     int iarr[] = {1,2,3,4,5};
//     double darr[] = {1.1,2.2,3.3,4.4,5.5};
//     std::cout<<sumEvenIndices(iarr)<<std::endl;
//     std::cout<<sumEvenIndices(darr)<<std::endl;
//     return 0;
// }

// 1.d. Create a template function in C++ called "reverseArray" that takes an array of
// any data type and its size as arguments. The function should reverse the elements
// of the array in-place. Demonstrate the usage of this function by reversing an array
// of integers and an array of characters.

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// template <typename T>
// void swap(T &arg1 , T &arg2){
//     T* temp = *arg1;
//     *arg1 = *arg2;
//     *arg2 = *temp;
// }

// template <typename T , size_t N> 
// void reverseinplace(T (&arr)[N]){
//     int begin = 0 , end = N-1;
//     while(begin<end){
//         T temp = arr[begin];
//         arr[begin] = arr[end];
//         arr[end] = temp;
//         begin++;
//         end--;
//     }
// }

// template <typename T>
// void myswap(T *arg1 , T *arg2){
//     T temp = *arg1;
//     *arg1 = *arg2;
//     *arg2 = temp;
// }

// template <typename T , size_t N> 
// void reverseinplace(T (&arr)[N]){
//     int begin = 0 , end = N-1;
//     while(begin<end){
//         myswap(&arr[begin], &arr[end]);
//         begin++;
//         end--;
//     }
// }

// int main()
// {
//     int iarr[] = {1,2,3,4,5,6,7,8};
//     reverseinplace(iarr);
//     for(auto i : iarr)
//         cout<<i<<" ";

//     return 0;
// }


// 2.a. Create a template class called "Stack" in C++. Implement appropriate member
// functions to push an element onto the stack, pop an element from the stack, and
// check if the stack is empty. Write a C++ program to demonstrate the usage of this
// class by pushing and popping elements of different data types onto the stack

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;


// template <typename T>
// class Stack{
//     private : 
//         vector<T> stack;
//         int top = -1;

//     public : 
    
//         Stack(){
//             stack = vector<T>();
//         }

//         void push(T element){
//             stack.push_back(element);
//             top++;
//         }

//         T pop(){
//             if(top == -1){
//                 cout<<"Stack is empty"<<endl;
//                 return -1;
//             }
//             T element = stack[top];
//             stack.pop_back();
//             top--;
//             return element;
//         }

//         bool isEmpty(){
//             return top == -1;
//         }

//         T Top (){
//             return stack[top];
//         }
// };


// int main()
// {
//     Stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.pop();
//     cout<<s.Top();
//     s.isEmpty();
    

//     return 0;
// }


// 2.b. Implement a template class called "LinkedList" in C++. The class should have
// appropriate member functions to insert an element at the front, delete an element
// from the front, and display the elements of the linked list. Write a program to
// demonstrate the usage of this class by inserting and deleting elements of different
// data types from the linked list

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// template <typename T> 
// struct Node { 
//     T data; 
//     Node* next; 
// };

// template <typename T>
// class LinkedList{
//     private : 
//         Node<T> *head;
//     public : 
//         LinkedList(){
//             head = NULL;
//         }

//         void insertFront(T data){
//             Node<T> * newNode = new Node<T>;
//             newNode-> data = data ;
//             newNode-> next = head;
//             head = newNode;
//         }

//         void deleteFront(){
//             if(head == NULL){
//                 cout<<"List is empty"<<endl;
//                 return;
//             }
//             Node<T> * temp = head;
//             head = head->next;
//             cout<<"Deleted element is "<<temp->data<<endl;
//             delete temp;
//         }

//         void display(){
//             Node<T> *temp = head;
//             while(temp != NULL){
//                 cout<<temp->data<<" ";
//                 temp = temp->next;
//             }
//         }
// };

// int main(){
//     LinkedList<int> l;
//     l.insertFront(10);
//     l.insertFront(20);
//     l.insertFront(30);
//     l.display();
//     l.deleteFront();
//     l.display();
//     return 0;
// }



// 2.c. Create a template class called "Pair" in C++. The class should have two private
// data members of any data type. Implement appropriate member functions to set
// and get the values of these members. Write a C++ program to demonstrate the
// usage of this class by creating two objects of different data types and
// setting/retrieving their values.


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;


// template <typename T , typename U>
// class Pair{
//     private: 
//         T first = T(); 
//         U second = U();
//     public : 
//         Pair(){
//             first = T(); //default constructor for T 
//             second = U();
//         }
//         Pair (T first , U second){
//             this->first = first;
//             this->second = second;
//         }

//         Pair (const Pair<T,U> &p){
//             this->first = p.first;
//             this->second = p.second;
//         }

//         T getFirst(){
//             return first;
//         }
//         T getsecond(){
//             return second;
//         }

//         void setFirst(T first){
//             this->first = first;
//         }
//         void setSecond(U second){
//             this->second = second;
//         }

//         void set(T first , U second){
//             this->first = first;
//             this->second = second;
//         }

//         void display(){
//             cout<<first<<" "<<second<<endl;
//         }

// };


// int main(){
//     Pair<int , string> p1;
//     p1.set(10,"abcd");
//     p1.display();
// }

// 2.d. Consider a base class called "Shape" and a derived class called "Rectangle" in
// C++. Implement these classes using templates. The base class should have two
// protected data members representing the dimensions of a shape, and the derived
// class should calculate and return the area of a rectangle using these dimensions.
// Write a program to demonstrate the usage of these classes by creating an object of
// the "Rectangle" class and calculating its area

// template<typename T> 
// class Shape{
//     protected:
//         T length;
//         T breadth;
//     public :
//         Shape(T length , T breadth){
//             this->length = length;
//             this->breadth = breadth;
//         } 
//         virtual void display(){
//             std::cout<<"helloworld";
//         } ;

//         virtual T area() = 0;

// };

// template<typename T>
// class Rectangle : public Shape<T>{
//     public : 
//         Rectangle(T length , T breadth) : Shape<T>(length , breadth){
//         }

//         void display() override {
//             std::cout << "Length: " << this->length << ", Breadth: " << this->breadth << std::endl;
//         }

//         T area() override {
//             return this->length * this->breadth;
//         }

// };

// int main(){
//     Rectangle<int> r(10,20);
//     std::cout<<r.area();
// }


// 3.a. Write a C++ program that uses the STL to implement a vector of integers.
// Populate the vector with some random integers and then use the STL algorithms
// to find the sum and average of all the elements in the vector

// int main(){
//     vector<int> v = {1,2,3,4,5,6,7,8,9,10};
//     int sum = accumulate(v.begin() , v.end() , 0);
//     int average = sum/v.size();
//     cout<<sum<<" "<<average;
//     return 0;

// }


// 3.b. Implement a C++ program that utilizes the STL stack container. The program
// should allow the user to enter a string of characters and then check if the entered
// string is a palindrome (reads the same forwards and backward) using the stack
// container from the STL.

// int main(){
//     stack<char> s;
//     string str;
//     cout<<"Enter the string"<<endl;
//     cin>>str;
//     for(char c : str){
//         s.push(c);
//     }
//     string rev = "";
//     while(!s.empty()){
//         rev += s.top();
//         s.pop();
//     }
//     if(str == rev){
//         cout<<"Palindrome"<<endl;
//     }
//     else{
//         cout<<"Not a palindrome"<<endl;
//     }
//     return 0;

// }

// 3.c. Write a C++ program that uses the STL map container to create a dictionary.
// The program should allow the user to enter words and their corresponding
// meanings, and then perform operations like searching for a word and displaying
// the entire dictionary.


// int main(){
//     map<string,string> dictionary;
//     while(true){
//         int choice = 4;
//         cout<<"Enter 1 to add a word and meaning, 2 to search for a word, 3 to display the dictionary, 4 to exit"<<endl;
//         cin>>choice;
//         choice = choice>4?4:choice;
//         switch (choice){
//             case 1 : {
//                 string word , meaning;
//                 cout<<"Enter the word"<<endl;
//                 cin>>word;
//                 cout<<"Enter the meaning"<<endl;
//                 cin>>meaning;
//                 dictionary[word] = meaning; // or dictionary.insert({word,meaning});
//                 break;
//             }
//             case 2 : {
//                 string word;
//                 cout<<"Enter the word to search"<<endl;
//                 cin>>word;
//                 if(dictionary.find(word) != dictionary.end()){
//                     cout<<dictionary[word]<<endl;
//                 }
//                 else{
//                     cout<<"Word not found"<<endl;
//                 }
//                 break;
//             }
//             case 3 : {
//                 for(auto i : dictionary){
//                     cout<<i.first<<" : "<<i.second<<endl;
//                 }
//                 break;
//             }
//             case 4 : {
//                 return 0;
//             }

//         }

//     }
// }


// 3.d. Create a C++ program that utilizes the STL set container. The program should
// allow the user to enter a series of integers and store them in the set. Implement
// functions to find the minimum, maximum, and average of the elements in the set

//set -> insert , erase , find , begin , end , rbegin , size , empty , count

// int maximum(set<int> s){
//     return *s.rbegin();
// }
// int minimum(set <int> s){
//     return *s.begin();
// }

// int average(set<int> s){
//     int sum = 0;
//     for(auto i : s){
//         sum += i;
//     }
//     return sum/s.size();
// }


// int main(){
//     set<int> s;

//     vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
//     for(int ar : arr){
//         s.insert(ar);
//     }
//     for(auto i : s){
//         cout<<i<<" ";
//     }
//     cout<<maximum(s)<<endl;
//     cout<<minimum(s)<<endl;
//     cout<<average(s)<<endl;
//     return 0;
// }


// 4.a. Write a C++ program to implement the Fibonacci series using template metaprogramming. The program should take a compile-time constant as input and
// generate the Fibonacci series up to that number




// using namespace std;

// template<int N>
// struct Fibonacci{
//     static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
// };

// template<>
// struct Fibonacci<0>{
//     static const int value = 0;
// };


// template<>
// struct Fibonacci<1>{
//     static const int value = 1;
// };

// int main(){
//     cout<<Fibonacci<10>::value;
//     return 0;
// }

//fibonacci -> 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610


// 4.b. Implement a template meta-program in C++ that calculates the factorial of a
// given number at compile-time. Write a program to demonstrate the usage of this
// template by calculating the factorial of a user-input number.


// template<int N> 
// struct Factorial{
//     static const int value = N * Factorial<N-1> :: value; // :: value is used to access the value of the static variable that is present in the class
// };

// template<>
// struct Factorial<0>
// {
//     static const int value = 1;
// };

// int main(){
//     std::cout<<Factorial<5>::value;
//     return 0;
// }   


// 4.c. Write a C++ program that utilizes template meta-programming to determine
// whether a given number is prime or not. The program should take a compile-time
// constant as input and display whether it is prime or not

// template < int N , int i = 2>
// struct is_prime{
//     static const bool value = (N % i) && is_prime<N,i-1>::value;
// };

// template <int N>
// struct is_prime<N,1>{
//     static const bool value = true;
// };

// template <int N>
// struct is_prime<N,0>{
//     static const bool value = false;
// };

// int main(){
//     std::cout<<is_prime<50>::value;
//     return 0;
// }


//4.d. Implement a C++ program that uses template meta-programming to generate
// the powers of a number. The program should take a base number and an
// exponent as compile-time constants and calculate the corresponding power at
// compile-time.

// template<int base , int exp>
// struct Power{
//     static const int value = base * Power<base,exp-1>::value;
// };

// template<int base>
// struct Power<base, 0> { // specialisation of the template class
//     static const int value = 1;
// };

// int main(){
//     std::cout<<Power<2,3>::value; // why does (2,3) not work , ans = because power is a template class and it needs to be defined as a template class
//     return 0;
// }



