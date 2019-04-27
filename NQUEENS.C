#include<stdio.h>
#include<conio.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
void print_solution(int n,int x[])
{
	char c[10][10];
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	c[i][j]='x';
	for(i=1;i<=n;i++)
	c[i][x[i]]='Q';
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c\t",c[i][j]);
		}
		printf("\n");
	}
}
int place(int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if((x[i]==x[k]) || abs(i-k)==abs(x[i]-x[k]))
		return FALSE;
	}
	return TRUE;
}
void nqueens(int n)
{
	int x[10],count=0,k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]+=1;
		while((x[k]<=n) && (!place(x,k)))
		{
			x[k]+=1;
		}
		if(x[k]<=n)
		{
			if(k==n)
			{
				count++;
				printf("Solution is %d\n",count);
				print_solution(n,x);
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		k--;
	}
	if(n==2 || n==3)
	{
		printf("There is no solution\n");
	}
}
void main()
{
	int n;
	clrscr();
	printf("Enter the no of queens\n");
	scanf("%d",&n);
	nqueens(n);
	getch();
}
/* Enter the no of queens
4                                                                               
Solution is 1                                                                   
x       Q       x       x                                                       
x       x       x       Q                                                       
Q       x       x       x                                                       
x       x       Q       x                                                       
Solution is 2                                                                   
x       x       Q       x                                                       
Q       x       x       x                                                       
x       x       x       Q                                                       
x       Q       x       x                                                       
				 */
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
