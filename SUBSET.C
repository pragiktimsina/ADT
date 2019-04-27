#include<stdio.h>
#include<conio.h>
int count,w[10],d,x[10];
void subset(int cs,int k,int r)
{
	int i;
	x[k]=1;
	if(cs+w[k]==d)
	{
		printf("Subset soluton=%d\n",++count);
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf("%d\t",w[i]);
		}
		printf("\n");
	}
	else if(cs+w[k]+w[k+1]<=d)
		subset(cs+w[k],k+1,r-w[k]);
	if((cs+r-w[k]>=d) && (cs+w[k+1]<=d))
	{
		x[k]=0;
		subset(cs,k+1,r-w[k]);
	}
	getch();
}
void main()
{
	int sum=0,i,n;
	clrscr();
	printf("Enter no of elements\n");
	scanf("%d",&n);
	printf("Enter the elements in ascending order\n");
	for(i=0;i<n;i++)
	scanf("%d",&w[i]);
	printf("Enter the required sum\n");
	scanf("%d",&d);
	for(i=0;i<n;i++)
	sum+=w[i];
	if(sum<d)
	{
		printf("no solution exist\n");
		return;
	}
	printf("solution is \n");
	count=0;
	subset(0,0,sum);
	getch();
}
/*
Enter no of elements
4
Enter the elements in ascending order
1 2 3 4
Enter the required sum
5
solution is
Subset soluton=1
Subset soluton=2
3


Enter no of elements
5
Enter the elements in ascending order
1
2
5                                                                               
6                                                                               
8                                                                               
Enter the required sum                                                          
9                                                                               
solution is                                                                     
Subset soluton=1                                                                
1       2       6                                                               
Subset soluton=2                                                                
1       8                                                                       
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                










                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                


*/







                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
