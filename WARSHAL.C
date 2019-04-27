#include<stdio.h>
#include<conio.h>
void warshal(int n,int a[100][100],int p[100][100])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			p[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][k]==1 && p[k][j]==1)
				p[i][j]=1;
			}
		}
	}
}
void main()
{
	int n,i,j,a[100][100],p[100][100];
	clrscr();
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	warshal(n,a,p);
	printf("The transitice closure matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	getch();
}
/*Enter the no of nodes
4                                                                               
Enter the adjacency matrix                                                      
0 0 0 1                                                                         
0 0 1 0                                                                         
0 1 0 0                                                                         
1 0 0 0                                                                         
The transitice closure matrix                                                   
1       0       0       1                                                       
0       1       1       0                                                       
0       1       1       0
1       0       0       1    */
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
