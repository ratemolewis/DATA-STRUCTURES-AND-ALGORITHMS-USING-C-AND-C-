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

void Insertion(int A[], int n)//it's best suited for linked list; no shifting of elements
//No. of passes is n-1
//No. of comparisons is n(n-1)/2=T=O(n^2)
//No. of swaps is n(n-1)/2=O(n^2)
//N/B it's adabtable and stable by default
{
    int i,j,x;
   
   for(i=1;i<n;i++)//n-1 passes
   {
     j=i-1;
     x=A[i];//take elem to be sorted
     while(j>-1&&A[j]>x)
     {
        A[j+1]=A[j];//copy elem to the foward of j
        j--;
     }

     A[j+1]=x;//copy the x elemnt to the right place
   }
}
int main()
{
    int A[]={11,13,7,2,6,9,4,5,10,3}, n=10, i;

Insertion(A,n);

for(i=0;i<10;i++)
 printf("%d ", A[i]);

printf("\n");


    return 0;
}
