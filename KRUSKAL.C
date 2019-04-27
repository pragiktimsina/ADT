#include<stdio.h>
#include<conio.h>
#define infinity 999
int find(int v,int s[])
{
	while(s[v]!=v)
	v=s[v];
	return v;
}
void krushkal(int n,int c[100][100])
{
	int t[100][2],u,v,s[100];
	int sum=0;
	int count=0;
	int i,j,k=0,min;
	for(i=0;i<n;i++)
		s[i]=i;
	while(count<n-1)
	{
		min=infinity;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(c[i][j]!=0 && c[i][j]<min)
			{
				min=c[i][j];
				u=i;
				v=j;
			}
		}
		if(min==999)break;
		i=find(u,s);
		j=find(v,s);
		if(i!=j)
		{
			t[k][0]=u;
			t[k][1]=v;
			count++;
			k++;
			sum=sum+min;
			s[j]=i;
		}
		c[u][v]=999;
		c[v][u]=999;
	}
	if(count==(n-1))
	{
		printf("Spanning tree exists\n");
		printf("Edges are\n");
		for(i=0;i<n-1;i++)
			printf("%d->%d\n",t[i][0],t[i][1]);
		printf("sum=%d\n",sum);
	}
	else
		printf("Spanning tree does not exist\n");
}
void main()
{
	int n,c[100][100],i,j;
	clrscr();
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	krushkal(n,c);
	getch();
}
/* Enter the number of nodes
7
Enter the cost adjacency matrix
0 999 4 999 999 2 3
999 0 999 6 999 5 9
4 999 0 10 8 999 1
999 6 10 0 7 999 999
999 999 8 7 0 999 999
2 5 999 999 999 0 999
3 9 1 999 999 999 0
Spanning tree exists
Edges are
2->6
0->5
0->6
1->5
1->3
3->4
sum=24    */






