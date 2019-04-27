#include<stdio.h>
#include<conio.h>
int max(int a ,int b);
void optimal(int v[10][10],int n,int m,int p[10],int w[10])
{
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			v[i][j]=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("The resultant matrix is \n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			printf("%d\t",v[i][j]);
			printf("\n");
	}
	printf("The optimal solution is %d \n",v[n][m]);
}
int max(int a,int b)
{
	return (a>b)? a:b;
}

void main()
{
	int i,j,n,m,w[10],p[10],v[10][10];
	clrscr();
	printf("Enter the no. of objects \n");
	scanf("%d",&n);
	printf("Enter the weight of the objects \n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Enter the profits of the object \n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("Enter the capacity of the knapsack \n");
	scanf("%d",&m);
	optimal(v,n,m,p,w);
	getch();
}


/*Enter the no. of objects
4
Enter the weight of the objects
1
3
2
1
Enter the profits of the object
12
34
56
32
Enter the capacity of the knapsack
4
The resultant matrix is
0       0       0       0       0
0       12      12      12      12
0       12      12      34      46
0       12      56      68      68
0       32      56      88      100
The optimal solution is 100




  */