#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[], int n)
//No of passes is n-1
//No of comparisons n(n-1)/2=O(n^2)=T
//No of swaps n(n-1)/2=O(n^2)=T
{//introduction of "flag variable to make buble sort adaptive i.e if the elements are sorted no need to continue checking."
    int i, j, flag;

    for(i=0;i<n-1;i++)// this handles the n-1 pass
    {   flag=0;//this to make this algo adaptive
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1]){
              swap(&A[j],&A[j+1]);
              flag=1;//this is not modified if the list is sorted
            }
             
             if(flag==0)//if the list is sorted no need to continue with remaining passes
              break;
        }
    }
}
int main()
{
    int A[]={3,7,9,10}, n=4, i;

Bubble(A,4);

for(i=0;i<4;i++)
 printf("%d ", A[i]);

printf("\n");


    return 0;
}
