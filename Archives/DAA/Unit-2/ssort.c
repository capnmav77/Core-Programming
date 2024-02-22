#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*, int*);
void ssort(int*,int);

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}
int main()
{
  struct timespec start;
  struct timespec end;	
  int *a;
  int n;
  int i;
  
  printf("Enter the size of the array ");
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  
  srand(time(0));
  for(i=0;i<n;i++)
     a[i]=rand() %100;
 printf("\nDisplaying the array..");
/*for(i=0;i<n;i++)
   printf("%d ",a[i]); */
clock_gettime(CLOCK_REALTIME, &start);
 ssort(a,n);
 clock_gettime(CLOCK_REALTIME, &end);
printf("\nAfter sorting..");
 /*for(i=0;i<n;i++)
  printf("%d  ",a[i]);*/
 printf("\ntime taken= %lf  seconds\n ",time_elapsed(start, end));
 
  }
  
 void ssort(int *a , int n)
  {
     int i,j,min;
     for(i=0;i<n-1;i++)
	 {
		 min=i;
	    for(j=i+1;j<n;j++)
		{
		   if(a[j] <a[min])
			   min=j;
		}
		swap(&a[j],&a[min]);
     	}
  }	 
  
  void swap(int *a, int *b)
  {
      int t= *a;
	  *a=*b;
	  *b=t;
	  }
  
  
	 
