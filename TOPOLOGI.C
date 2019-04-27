//on infinite loop
#include<stdio.h>
#include<conio.h>
void find_indegree(int a[10][10],int n,int indegree[10])
{
	int j,i,sum;
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<n;i++)
		sum+=a[i][j];
		indegree[j]=sum;
	}
}
void toposort(int a[10][10],int n)
{
	int u,v,t[10],s[10],indegree[10],top,k,i;
	find_indegree(a,n,indegree);
	top=-1;
	k=0;
	for(i=0;i<n;i++)
	if(indegree[i]==0)
	s[++top]=i;
	while(top!=1)
	{
		u=s[top--];
		t[k++]=u;
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1)
			{
				indegree[v]--;
				if(indegree[v]==0)
				s[++top]=v;
			}
		}
	}
	printf("Topological sorting is\n");
	for(i=0;i<n;i++)
	printf("%d\t",t[i]);
	return;
}
void main()
{
	int n,a[10][10],i,j;
	clrscr();
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	toposort(a,n);
	getch();
}
/*Enter the number of nodes
4
Enter the adjacency matrix
0 1 1 0
0 0 0 0
0 0 0 0
0 0 0 1
Topological sorting is
0       -1      1       2

 */
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
