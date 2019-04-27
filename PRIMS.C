#include<stdio.h>
#include<conio.h>
#define infinity 999
void prim(int cost[100][100],int n,int visited[100],int p[100],int d[100])
{
	int mincost,count=0,i,j,v,source,u,t[100][2],k,sum;
	k=0;
	sum=0;
	mincost=infinity;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(cost[i][j]<mincost)
		{
			mincost=cost[i][j];
			source=i;
		}
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		p[i]=source;
		d[i]=cost[source][i];
	}
	visited[source]=1;
	for(i=0;i<n;i++)
	{
		u=-1;
		mincost=infinity;
		for(j=0;j<n;j++)
		{
			if((visited[j]==0)&&(d[j]<mincost))
			{
				mincost=d[j];
				u=j;
			}
		}
		if(u==-1)break;
		visited[u]=1;
		t[k][0]=p[u];
		t[k][1]=u;
		count++;
		k++;
		sum=sum+mincost;
		for(v=0;v<n;v++)
		if((visited[v]==0)&&(cost[u][v]<d[v]))
		{
			d[v]=cost[u][v];
			p[v]=u;
		}
	}
	if(count==n-1)
	{
		printf("spanning tree exists\n edges of the spanning tree is \n");
		for(i=0;i<n-1;i++)
			printf("%d->%d\n",t[i][0],t[i][1]);
		printf("Sum =%d\n",sum);
	}
	else
		printf("Spanning tree does not exist\n");
}
void main()
{
	int n,i,j,cost[100][100],visited[100],p[100],d[100];
	clrscr();
	printf("Enter the number of vertices int graph\n");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&cost[i][j]);
	prim(cost,n,visited,p,d);
	getch();
}
/*   Enter the number of vertices int graph
5
Enter the cost adjacency matrix
0 4 5 999 999
4 0 999 5 2
5 999 0 3 999
999 5 3 0 3
999 2 999 3 0
spanning tree exists
 edges of the spanning tree is
0->1
1->4
4->3
3->2
Sum =12

Enter the number of vertices in graph
5
Enter the cost adjacency matrix
0 6 999 9 999
6 0 8 999 5
999 8 0 999 2
9 999 999 0 1
999 5 2 1 0
spanning tree exists
 edges of the spanning tree is
0->1
1->4
4->3                                                                            
4->2                                                                            
Sum =14                                                                         
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

*/


