#include<stdio.h>
#include<conio.h>
#include<string.h>
#define infinity 999
int dijkstra(int n,int cost[100][100],int visited[100],int p[100],int distance[100],int source,int dest)
{
	int i,u,v,mincost,j;
	for(i=0;i<n;i++)
	{
		distance[i]=cost[source][i];
		p[i]=source;
		visited[i]=0;
	}
	visited[source]=1;
	for(i=0;i<n;i++)
	{
		u=-1;
		mincost=infinity;
		for(j=0;j<n;j++)
		if((visited[j]==0)&&(distance[j]<mincost))
		{
			mincost=distance[j];
			u=j;
		}
		if(u==-1)
		return;
		if(u==dest)
		return;
		visited[u]=1;
		for(v=0;v<n;v++)
		if((visited[v]==0)&&((distance[u]+cost[u][v]<distance[v])))
		{
			distance[v]=cost[u][v]+distance[u];
			p[v]=u;
		}
	}
}
void main()
{
	int n,a[100][100],visited[100],p[100],distance[100],source,dest,i,j;
	clrscr();
	printf("enter the no of verticesin graph\n");
	scanf("%d",&n);
	printf("enter adjacency matrix\n 999 for no edge\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("enter source node\n");
	scanf("%d",&source);
	for(dest=0;dest<n;dest++)
	{
		dijkstra(n,a,visited,p,distance,source,dest);
		if(distance[dest]==infinity)
		printf("\n node=%d is not reachable from %d",dest,source);
		else
		{
			printf("path from %d to %d is \n",dest,source);
			i=dest;
			while(i!=source)
			{
				printf("%d<-",i);
				i=p[i];
			}
			printf("%d\n",i);
			printf("\n distance =%d",distance[dest]);
		}
	}
	getch();
}