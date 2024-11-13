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
//Bets case(sorted list) O(n)
//Worst case(reverse order data) O(n^2)
//N/B it's adabtive and stable by default
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

void SelectionSort(int A[],int n)
//No. of comparisons )=T=(n^2) 
//No. of swaps O(n)
//not statble and adaptive
//Intermediate result are useful
{
    int i,k,j;
    for(i=0;i<n;i++)//for selection a position to be filled
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])//if the elem at j is smaller than that at k, bring k to j
              k=j;
        }
        swap(&A[i],&A[k]);//at the end of the inner loop k will be pointing at the smallest elem; swap with i
    }
}
int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10, i;

SelectionSort(A,n);

for(i=0;i<10;i++)
 printf("%d ", A[i]);

printf("\n");


    return 0;
}
