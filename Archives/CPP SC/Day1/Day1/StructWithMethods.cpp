#include <iostream>    

using namespace std;    

struct Rectangle    
{      
	int width, height;      
	Rectangle(int w, int h)      
	{      
		width = w;      
		height = h;      
	}      

	void areaOfRectangle() 
	{       
		cout<<"Area of Rectangle is: "<<(width*height); 
	}      
};      

int main(void) 
{    
	Rectangle rec = Rectangle(4,6);    //as long as parameters are different we are fine [constructor is just another function, when it actually compiles , there is nothing known as public , private and class. everything is a structure]
	rec.areaOfRectangle();    
	return 0;    
}    