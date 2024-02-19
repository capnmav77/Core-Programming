 //program to implement Topological sorting using source vertex removal method
 #include<stdio.h>
 int visit[100];
 void creategraph();
  void top_sort();
 int a[100][100],n;
 void push(int *, int *, int);
 int pop(int *, int *);
 int isempty(int);
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
  
   top_sort();
 
  }



  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=1;
     }
  }

  void top_sort()
  {
	  int count=0;
      int t[100];//topological sequence
     int s[10]; //stack
	 int top=-1;
	 int v,w,i,j;
	 int indegree[10];
	
	 for(i=1;i<=n;i++)
		 indegree[i]=0;
	 //finding indegree of the vertices
	 for(i=1;i<=n;i++)
	 {
		 for(j=1;j<=n;j++)
			 if(a[i][j]==1)
	              indegree[j]++;
	 
	 }
	 //finding the source vertices
	 for(i=1;i<=n;i++)
	 {
		 if(indegree[i]==0)
			 push(s,&top,i);
	 }	 
	
     //while the stack is not empty	
     while(!isempty(top))
	 {
		 v=pop(s,&top);
		 t[count++]=v;
		 for(w=1;w<=n;w++)
		 {
			 if(a[v][w]==1)
			 {
				 indegree[w]--;
				 if(indegree[w]==0)
					 push(s,&top,w);
			 }
		 }
	 }
if(count==n)
{
	printf("The topological sequence is ...\n");
    for(i=0;i<count;i++)
		printf("%d ",t[i]);
}
else
	printf("The sequence not possible");
  }
   
    void push(int *s, int *t, int x)
	{
		++*t;
		s[*t]=x;
	}

  int pop(int *s, int *t)
  {
	  int x;
	  x=s[*t];
	  --*t;
	  return x;
  }
	 
int isempty( int t)
{	 
  if(t==-1)
	  return 1;
  return 0;
}
			 
			 
			 
		 
		 
		 
		 
		 
	


	
		 
			 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 




 /*void top_sort()
  {
      int i,j;
	  int indegree[10];
	  for(i=1;i<=n;i++)
		  indegree[i]=0;
	  for(i=1;i<=n;i++)
	  {
		  for(j=1;j<=n;j++)
			  if(a[i][j]==1)
				  indegree[j]++;
	  }
    for(i=1;i<=n;i++)
    {
       if((visit[i]==0)&&(indegree[i]==0))
           dfs(i);
	}	   

	printf("\nCount = %d\n",count);
      
	  if(count==n)
	  {
	     printf("The topological sequence is ...\n");
         for(i=count-1;i>=0;i--)
          printf("%d  ",t[i]);
	  }
	  else
		 printf("The sequence is not possible...");
  }
*/

/*  void dfs(int v)
  {
    int w;
    visit[v]=1;
    
    for(w=1;w<=n;w++)
    {
      if((a[v][w]==1)&&(visit[w]==0))
        dfs(w);
    }
    t[count++]=v;
  }*/
   

 