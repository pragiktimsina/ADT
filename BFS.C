#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void bfs(int a[100][100],int n,int source)
{
	int f,r,q[100],u,v,i,s[100];
	for(i=0;i<n;i++)
	{
		s[i]=0;
	}
	f=0;
	r=0;
	q[r]=source;
	s[source]=1;
	while(f<=r)
	{
		u=q[f++];
		for(v=1;v<n;v++)
		{
			if(a[u][v]==1 && s[v]==0)
			{
				s[v]=1;
				q[++r]=v;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(s[i]==0)
		{
			printf("Vertix %d is not reachable\n",i);
		}
		else
		{
			printf("Vertix %d is reachable\n",i);
		}
	}
}
void main()
{
	int n,adj[100][100],i,j,source;
	clrscr();
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	bfs(adj,n,source);
	getch();
}