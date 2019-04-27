#include<stdio.h>
#include<conio.h>
void read(int n,int cost[10][10])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
}
void dfs(int n,int cost[20][20],int u,int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<n;v++)
	{
		if(cost[u][v]==1 && s[v]==0)
		dfs(n,cost,v,s);
	}
}
int connectivity(int n,int cost[20][20])
{
	int i,j,flag,s[10];
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		s[i]=0;
		dfs(n,cost,j,s);
		flag=0;
		for(i=0;i<n;i++)
		if(s[i]==0)
		flag=1;
		if(flag==0)
		return 0;
	}
	return 0;
}
void main()
{
	int n,cost[20][20],flag,i,j;
	clrscr();
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&cost[i][j]);
	}
	flag=connectivity(n,cost);
	if(flag==1)
	printf("graph is connected\n");
	else
	printf("graph is not connected\n");
	getch();
}