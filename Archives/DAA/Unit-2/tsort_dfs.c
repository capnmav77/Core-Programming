 //program to implement Topological sorting using DFS
 #include<stdio.h>
 int visit[100];
 void creategraph();
 
 void top_dfs(int);
 void top_sort();
 int a[100][100],n;
 int count;
 int t[100];
 
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




 void top_dfs(int v)
 {
	 int w;
	 visit[v]=1;
	 for(w=1;w<=n;w++)
	 {
		 if((a[v][w]==1)&&(visit[w]==0))
			 top_dfs(w);
	 }
	    t[count++]=v;
 }		
	
  void top_sort()
  {
	    int i;
       	for(i=1;i<=n;i++)
    	{
      	 if(visit[i]==0)
          		top_dfs(i);
        }	   

		     printf("The topological sequence is ...\n");
         	    for(i=count-1;i>=0;i--)
          		printf("%d  ",t[i]);
	  
	    }
  

 
 
 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 




 