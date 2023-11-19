/*Program to find the shortest path from source vertex 1 to all the other vertices of the 
directed/undirected weighted graph by implementing dijkstras algorithm */


#include<stdio.h>

	int a[10][10];
	int vertices;
	void dijkstras(int);
	int findmin(int*,int*);
	void display(int*,int);

	void display(int *p, int i)
	{
      printf("%d-->",i);

      while(p[i]!=0)
    {
	 printf("%d-->",p[i]);
	 i=p[i];
   }
 }


void addedge(int x,int y,int c,int type)
{
	
	if((x>vertices)&&(y>vertices))
		printf("Invalid Edge");
	else
		if(type==1) //directed graph
			a[x][y]=c;
		else
			 a[x][y]=a[y][x]=c; //undirected graph
	
}

	
void dijkstras(int s)
{
	int p[100];//path array
	int d[100]; //distance array
	int v[100]; //visited array
		
	for(int i=1;i<=vertices;i++)
	{
		d[i]=a[s][i];
		if(d[i]!=999)
			p[i]=s;
		else
			p[i]=0;
		v[i]=0;
	}
	p[1]=0;
	v[s]=1;
	for(int i=1;i<=vertices-1;i++)
	{
		int k=findmin(d,v);
		v[k]=1;
		for(int u=1;u<=vertices;u++)
		{
			if((v[u]==0)&&(d[u]>d[k]+a[k][u]))
			{
				d[u]=d[k]+a[k][u];
				p[u]=k;
			}
		}

	}
	printf("The cost of the paths are");
	for(int i=1;i<=vertices;i++)
		printf("\nThe cost of  %d to %d is  %d",s,i,d[i]);
	printf("\nthe paths are...");
	for(int i=2;i<=vertices;i++)
	{
	 printf("\nThe path from 1 to %d is ", i);
	 display(p,i);
	}
}


 int findmin(int *d, int *v)
 {
	 int min=0;
	 for(int i=1;i<=vertices;i++)
	 {
		 if(v[i]==0)
		 {
			 min=i;
		     break;
		 }
	 }

	 for(int j=min+1;j<=vertices;j++)
	 {
		 if((v[j]==0)&&(d[j]<d[min]))
		  min=j;
	 }
	 return min;
 }
	
 
 void main()
	{
		int x,y,c,type;
		
		printf("Enter the number of vertices..");
		scanf("%d",&vertices);

		
		printf("Enter the type of the graph <1-directed 2-undirected>..");
		scanf("%d",&type);
		
		for(int i=1;i<=vertices;i++)
		{
			for(int j=1;j<=vertices;j++)
				if(i==j)
					a[i][j]=0;
			else
				a[i][j]=999;
		}
		printf("Enter the edges..\n");
		while(1)
		{
			printf("Enter the source(-9 to end), destination and the the cost of edge..");
			scanf("%d",&x);
				if(x==-9)
					break;
			scanf("%d",&y);
			scanf("%d",&c);
		    addedge(x,y,c,type);
		}	

		 dijkstras(1);// 1 is taken as the source vertex
		
	}




