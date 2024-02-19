#include<stdio.h>
int main()
{
	int multiply(int,int);
	int m,n,r;
	
	printf("Enter the numbers of n and m");
	scanf("%d %d",&n,&m);
	r=multiply(n,m);
	
	printf("\nresult = %d\n",r);
}

int multiply(int n, int m)
{
	int result;
	result=0;
	while(n>0)
	{
		if(n%2)
			result = result + m;
		m=2*m;
		n=n/2;
	}
	return result;
}

		
/*int multiply(int n, int m)
 {
	 if(n==1)
	    return m;
   	if(n%2)
			 return (m+multiply(n/2,2*m));
		 else
			 return(multiply(n/2, 2*m));
	}
	*/