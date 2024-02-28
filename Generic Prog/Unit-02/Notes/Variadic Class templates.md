- Class templates may have variable number of template arguments. this is key to building some categories of types , such as tuple and variant , that are avail in stl . 
- Tuple - fixed size collection of heterogenous values.
- when implementing it : 
	- use a recursive pattern with 2 overloads, one for general case and one for ending recursion . 
- look into tuple_implementation.cpp
	- ### Pack expansion.
	- it's like a linked list , but the terminology used: **Pack expansion.**
	- we recurse through the values until the base template is called.
	- 1.we need to fetch the type and value of that index .
		- type :
			- implement a recursive call -> template <size_t N, typename T, typename... Ts> 
			- therefore when N /== 0 , return the type at that index . 
		- value : 
			- return type is the value at that node 
			- we recurse till N becomes 0 , then we have reached the node N 
			- we then return the value at the that node. 
## Fold expressions 
- from earlier implementation we needed a pack expression function as well as a overloaded base case in order to take care of the base case . 
- therefore in order to get over this huge implementation we use fold expression . 

### Variadic alias templates 
- wherever there is a template , it can be aliased using 'using'
- check out the slides 

## DeclType Specifier 
- it is used to deduce the **type from the expression** and assign the value to the variable in context of normal programming and not template
- A