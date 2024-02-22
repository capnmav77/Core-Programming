//program to find MST of a weigthed undirected by implementing prims algorithm .

   #include<stdio.h>
    void addedge(int ,int,int);
	void prims();
	int findmin(int*,int*);
	int a[10][10];
	int vertices;
	
void addedge(int x,int y,int c)
{
	
	if((x>vertices)&&(y>vertices))
		printf("Invalid Edge");
	else
	  a[x][y]=a[y][x]=c;
	
}

	
void prims()
{
	int n[100];
	int d[100];
	int v[100];
	int t[10][3];
	int cost=0;

	for(int i=1;i<=vertices;i++)
	{
		d[i]=a[1][i];
		if(d[i]!=999)
			n[i]=1;
		else
			n[i]=0;
		v[i]=0;
	}

	v[1]=1;
	for(int i=1;i<=vertices-1;i++)
	{
		int k=findmin(d,v);
		v[k]=1;
		t[i][1]=n[k];
		t[i][2]=k;
		cost=cost+d[k];
		for(int u=1;u<=vertices;u++)
		{
			if((v[u]==0)&&(d[u]>a[k][u]))
			{
				d[u]=a[k][u];
				n[u]=k;
			}
		}

	}
	printf(" the edges of the spanning tree are...\n");
	for(int i=1;i<=vertices-1;i++)
		printf("%d -->%d\n",t[i][1],t[i][2]);

	printf("The cost of the tree is %d",cost);
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
		int x,y,c;
		
		printf("Enter the number of vertices..");
		scanf("%d",&vertices);
		
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
			printf("Enter the source(-9 to end), destination and the the cost of edge..\n");
			scanf("%d",&x);
			if(x==-9)
					break;
			scanf("%d",&y);
			scanf("%d",&c);
		    addedge(x,y,c);
		}	
		
		prims();
		
	}





