#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct gift 
{
	int noofgift;
	char nm[20];
	
};
void setpriority(gift a[], int low, int h)
{
    int pivot, i, j; gift t;
    if (low < h)
    {
        pivot = low;
        i = low;
        j = h;
        while (i < j) 
        {
            while (a[i].noofgift <= a[pivot].noofgift && i <= h)
            {
                i++;
            }
            while (a[j].noofgift > a[pivot].noofgift && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        t = a[j];
        a[j] = a[pivot];
        a[pivot]= t;
        setpriority(a, low, j - 1);
        setpriority(a, j + 1, h);
    }
}
int main()
{ struct gift obj[10] ;
	int i ;
 for(i=0;i<10;i++)
 { 
 printf("enter name ");
 scanf("%s",&obj[i].nm);
 printf("enter no of gift for student %s:-",obj[i].nm);
 scanf("%d",&obj[i].noofgift);
 
 }

  setpriority(obj, 0, 10);	 
    printf("After applying after arranging \n");
    for (i=10; i>0; i--)
    { printf("\nstudent %s:-",obj[i].nm);
        printf("%d ", obj[i].noofgift);
    }
    printf("\n");
 }
