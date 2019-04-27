#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
void simple_merge(int a[],int low,int mid,int high)
{
	int i,j,k,c[10000];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		a[i]=c[i];
	}
}
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		simple_merge(a,low,mid,high);
		delay(10);
	}
}
void main()
{
	int a[10000],n,i,mid,low,high;
	float res;
	clock_t end,start;
	clrscr();
	printf("Enter the size of an array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	res=(end-start)/CLK_TCK;
	printf("Time taken to sort to %d elements %f\n",n,res);
	getch();
}
