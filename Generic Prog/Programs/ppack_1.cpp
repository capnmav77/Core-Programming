template <typename T> 
T step_it(T value) 
{ 
	return value+1; 
}
template <typename... T> 
int sum(T... args) 
{ 
	return (... + args); 
}
template <typename... T> 
void do_sums(T... args) 
{ 
	auto s1 = sum(args...);   	// sum(1, 2, 3, 4) 
	auto s2 = sum(42, args...);    	// sum(42, 1, 2, 3, 4) 
	auto s3 = sum(step_it(args)...);            	// sum(step_it(1), step_it(2),... step_it(4)) 
}
do_sums(1, 2, 3, 4); 
