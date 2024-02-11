// Example: define member function with argument outside the class

#include<iostream>
#include<string.h>
using namespace std;

class Person
{
	int id;
	char name[100];
	
	public:
		void set_p(int,char[]);
		void display_p();
};

void Person::set_p(int id,char n[])
{
	this->id=id;
	strcpy(this->name,n);		
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
	void set_s(int,char[],char[],int);
	void display_s();
};

void Student::set_s(int id,char n[],char c[],int f)
{
	set_p(id,n);
	strcpy(course,c);
	fee=f;
}


void Student::display_s()
{
	display_p();
	cout<<"\t"<<course<<"\t"<<fee;
}

main()
{
	Student s;
        char name[] = {"Ram"};
        char course[] = {"cse"};
        s.set_s(1001, name,course,2000);
	s.display_s();
	return 0;
}
