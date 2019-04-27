// not proper output
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
int partition(int a[],int low,int high)
{
	int temp,key,i,j;
	key=a[low];
	i=low;
	j=high+1;
	while(i<=j)
	{
		do
		{
			i=i+1;
		}
		while(key<a[i]);
		do
		{
			j=j-1;
		}
		while(key<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int low,int high)
{
	int k;
	if(low<high);
	{
		k=partition(a,low,high);
		quicksort(a,low,k-1);
		quicksort(a,k+1,high);
	}
	delay(10);
}
void main()
{
	int a[1000],n,i,mid,low,high;
	float res;
	clock_t end,start;
	clrscr();
	printf("Enter the size of array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	printf("The unsorted array\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	start=clock();
	quicksort(a,0,n-1);
	end=clock();
	res=(end-start)/CLK_TCK;
	printf("The sorted array\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	res=(end-start)/CLK_TCK;
	printf("Time taken to sort %d element is %f\n",n,res);
	getch();
}