#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bsort(int*,int);
void swap(int *,int *);
void rbsort(int* , int );
double time_elapsed(struct timespec, struct timespec );
int main()
{
	struct timespec start;
	struct timespec end;
	int *a;
	int n,i;
	printf("Enter the size of the array");
	scanf("%d",&n);
	//create array
	 a= (int*)malloc(sizeof(int)*n);
	 srand(time(0));
      //fill in the array
	  for(i=0;i<n;i++)
		  a[i]=rand()%100;
	  
	  printf("\nDisplaying the array");
	  for(i=0;i<n;i++)
		  printf("%d ",a[i]);
	  clock_gettime(CLOCK_REALTIME, &start);
	  
	 // bsort(a,n);
	 rbsort(a,n);
	
	  clock_gettime(CLOCK_REALTIME, &end);
	  printf("\nafter sorting");
	 for(i=0;i<n;i++)
		  printf("%d ",a[i]);
	  
	  printf("\n Time taken = %lf seconds ",time_elapsed(start,end));
}

//bubble sort function

              void bsort(int* a, int n)
             {
	            int i,j;
			    int anyswap;
	           for(i=0;i<n;i++) // no of passes
	           {
				    anyswap=0;
		            for(j=0;j<n-1-i;j++) // i elements already sorted
		           {
           		       if(a[j]>a[j+1])
					   {
             		       swap( &a[j], &a[j+1]); // or swap((a+j), (a+j+1)) //not swap(a[j], a[j+1])
				          anyswap=1;
					   }
		            }  
				 if(anyswap==0)
					 break;
                }
             }	
	       //recursive bubble sort
           void rbsort(int* a, int n)
             {
	            int i,j;
			    int anyswap;
	         	   anyswap=0;
				   if(n==1)
					   return;
		            for(j=0;j<n-1;j++) 
		           {
           		       if(a[j]>a[j+1])
					   {
             		       swap(&a[j],&a[j+1]);
				          anyswap=1;
					   }
		            }  
				 if(anyswap==1)
					 rbsort(a,n-1);
                }
             	
		
	
void swap(int *a, int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}  
		
		
double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t= (end.tv_sec - start.tv_sec);
	t=t+(end.tv_nsec - start.tv_nsec)*0.000000001;
	return t;
}		
		
		
		
		
		
		
		
	
	

	  
	  
	  
	  
	  