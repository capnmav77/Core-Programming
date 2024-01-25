// Example: define member function without argument outside the class

#include<iostream>
using namespace std;

class Person
{
	int id;
	char name[100];
	
	public:
		void set_p();
		void display_p();
};

void Person::set_p()
{
	cout<<"Enter the Id:";
	cin>>id;
	cin.ignore (20, '\n');
	cout<<"Enter the Name:";
	cin.get(name,100);
}

void Person::display_p()
{
	cout<<endl<<id<<"\t"<<name;
}

class Student: private Person
{
	char course[50];
	int fee;
	
	public:
		void set_s();
		void display_s();
};

void Student::set_s()
{
	set_p();
	cout<<"Enter the Course Name:";
	cin.ignore (20, '\n');
	cin.getline(course,50);
	cout<<"Enter the Course Fee:";
	cin>>fee;
}

void Student::display_s()
{
	display_p();
	cout<<"\t"<<course<<"\t"<<fee;
}

main()
{
	Student s;
	s.set_s();
	s.display_s();
	return 0;
}
