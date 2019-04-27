#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void bubblesort(int a[1000],int n)
{
	int i,j,temp;
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]>a[j+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		delay(10);
	}
}
void main()
{
    int a[10000],i,n;
    float res;
    clock_t end,start;
    clrscr();
    printf("Enter the number of elements to be sorted:\n");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
	a[i]=rand();
    }
    printf("unsorted array\n");
    for(i=0;i<n;++i)
	printf("%d\n",a[i]);
    start=clock();
    bubblesort(a,n);
    end=clock();
    res=(end-start)/CLK_TCK;
    printf("Sorted array is \n");
    for(i=0;i<n;i++)
	 printf("%d\n",a[i]);
    printf("The time taken to sort %d elements in %f\n",n,res);
    getch();
}

