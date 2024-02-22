- when checking for functions - twophase.cpp
- we have 2 methods 
	- base parser and a parser
	- since init is a non-dependent name , it is not resolved , therefore error comes up
	- therefore in order to resolve this we can use scope resolution or we can use specialized base class 

## Dependent Type name 
- so far we have seen examples where dependent name was a function 
- now we declare the dependent name as type 
- a dependent name -> is a name that depends on the type or value of a template parameter
- it can't be resolved until the type value of the template is instantiated . this is because the type or value of the template isn't known until the template is instantiated.

- the template keyword can only follow the scope resolution operator , the arrow operator . 

- #### Current Instantiation
	- the requirement to use the typename and template keywords to disambiguate the names may be avoided 
	- when the compiler is able to deduce the 


- #### Template Argument Deduction
	- the compiler tries to compare the type of argument to the template parameter . must be of certain structure order in order for template argument deduction to work . 
	- ta_deduct.txt