#include<stdio.h>
#include<conio.h>
#define infinity 99
int min(int a,int b)
{
	return(a<b)?a:b;
}
void floyd(int n,int a[10][10],int d[10][10])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
void main()
{
	int i,j,k,a[10][10],d[10][10],n;
	clrscr();
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("distance matrix\n");
	floyd(n,a,d);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",d[i][j]);
		}
		printf("\n\n");
	}
	getch();
}
/*Enter the no of nodes
4
Enter the adjacency matrix
0 2 3 99
2 0 99 99
99 7 0 1                                                                        
6 99 99 0                                                                       
distance matrix                                                                 
0       2       3       4                                                       
                                                                                
2       0       5       6                                                       
                                                                                
7       7       0       1                                                       
                                                                                
6       8       9       0    */
                                                                                

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
