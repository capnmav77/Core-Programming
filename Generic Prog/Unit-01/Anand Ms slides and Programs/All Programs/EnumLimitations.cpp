#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Defining enum1 Gender
	enum Gender { Male, Female };

	// Defining enum2 Gender2 with same values
	// This will throw error
	enum Gender2 { Male, Female };

	// Creating Gender type variable
	Gender gender = Male;
	Gender2 gender2 = Female;

	cout << gender << endl << gender2;

	// One more instance of an error
	// Defining enum1 Gender
    	enum Gender { Male, Female };
 
    	// Creating Gender type variable
    	Gender gender = Male;
 
 	// creating a variable Male this will throw error
    	int Male = 10;

	// One more instance of error: Defining enum1 Gender
    	enum Gender { Male, Female };
 
    	// Defining enum2 Color
    	enum Color { Red, Green };
 
    	// Creating Gender type variable
    	Gender gender = Male;
    	Color color = Red;
 
    	// Upon comparing gender and color it will return true as both have value 0
    	// which should not be the case actually
    	if (gender == color)
        	cout << "Equal";

	return 0;
}
