#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void selection_sort();
int a[1000], n;
void main()
{
    int i;
    float res;
    clock_t end,start;
    clrscr();
    printf("\nEnter size of an array: ");
    scanf("%d", &n);
    printf("\nEnter elements of an array:\n");
    for(i=0; i<n; i++)
	a[i]=rand();
    start=clock();
    selection_sort();
    end=clock();
    res=(end-start)/CLK_TCK;
    printf("\nAfter sorting:\n");
    for(i=0; i<n; i++)
	printf("%d\n", a[i]);
    printf("Time taken to sort the %d elements is %f",n,res);
    getch();
}
void selection_sort()
{
    int i,j,min,temp;
    for (i=0; i<n; i++)
    {
	min = i;
	for (j=i+1; j<n; j++)
	{
	    if (a[j] < a[min])
		min = j;
	}
	delay(20);
	temp = a[i];
	a[i] = a[min];
	a[min] = temp;
    }
}
/*
Enter size of an array: 4                                                       
                                                                                
Enter elements of an array:                                                     
                                                                                
After sorting:                                                                  
130                                                                             
346                                                                             
1090                                                                            
10982
Time taken to sort the 4 elements is 0.054945                                   
						 */
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
