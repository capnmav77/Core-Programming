//implement kruskals algorithm to generate a minimum cost spanning tree 
// for a given undirected weighted graph

#include<stdio.h>


	struct edge
	{
	int u,v,wt;
	};

    void addedge(int ,int,int);
	void sortedges();
	void kruskal();
	int find(int);
	void merge(int,int);
	
	int a[10][10]; // cost adjecency matrix
	int vertices; //no of vertices in graph
	struct edge e[100];  //array to store the edges
    int ecount=0; //no of edges in the graph
	int comp[100];//array to store the components of the vertices
	
  void addedge(int x,int y,int c)
{
	
	if((x>vertices)&&(y>vertices))
		printf("Invalid Edge");
	else
	{
	  a[x][y]=a[y][x]=c;
	  e[ecount].u=x;
	  e[ecount].v=y;
	  e[ecount].wt=c;
      ecount++;
	}
}


//sort edges of the graph using bubble sort
void sortedges()
{
	struct edge temp;
	for(int i=0;i<ecount;i++)
	{
		for(int j=0;j<ecount-1;j++)
		{
			if(e[j].wt>e[j+1].wt)
			{
				temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
         }
	}
}

// function to find the component of a vertex
int find(int i)
{
	while(i!=comp[i])
		i=comp[i];
	return i;
}

// function to merge the components
void merge(int j, int k)
{
	if (k >j)
	  comp[k]=j;
  else
	  comp[j]=k;
}

void kruskal()
{
	int t[20][3];// array to store the tree edges
	struct edge temp;
	int tree_edge=0; // no. of edges in the tree
	int cost=0;
	
	sortedges();
	
	for(int i=1;i<=vertices;i++)
		comp[i]=i;
			
	for(int i=0;i<ecount;i++)
	{
     	 temp=e[i];
	  int a=temp.u;
	  int b=temp.v;
	  int w=temp.wt;
	  // find which component a and b belongs
	  int j=find(a); 
	  int k=find(b);

	  //add to the tree if they belong to different components
	  if(j!=k) 
	  {
		 t[tree_edge][1]=a;
		 t[tree_edge][2]=b;
		 cost=cost+w;
		 merge(j,k);
		 tree_edge++;
	  }
	}
	if(tree_edge==vertices-1)
	{
		printf("The edges spanning tree are\n");
		for(int m=0;m<tree_edge;m++)
			printf("%d -->%d\n",t[m][1],t[m][2]);

		printf("The cost of the spanning tree is  %d",cost);
	}
	else
		printf("Spanning tree not possible");
}

void main()
	{
		int x,y,c;
		
		printf("Enter the number of vertices..\n");
		scanf("%d",&vertices);

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
		kruskal();
	}
