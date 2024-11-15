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

int partition(int A[],int l, int h)
//Quick sort partioning procedure, used recursively
//2 elem are the least that can be partitioned
//__INT_MAX__, acts at the stopping mart for i, serving as infinity which is the intmax, while sorted ement acts as the upper bound for the left list
{
    int pivot=A[l];
    int i=l, j=h;
    do{
    do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        
        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);

      swap(&A[l],&A[j]);//the element is placed at sorted position, such that smaller and greater elem on the left and right respectively.
      return j;//the index of the partioned elem
}

void QuickSort(int A[], int l, int h)
//Best/Average case(partioning happening in the middle) T=O(nlogn)
//Worst case(partioning happening at any end) T=O(n^2)
{
    int j;
    if(l<h)//works for atleast two elements
    {
        j=partition( A, l,  h);
        QuickSort(A,l,j);//left list runs fron l to j-1 but j position sorted elem acts as infinity/stoping condition for i
        QuickSort(A,j+1,h);
    }
}

void merge(int A[],int l, int mid, int h)
//merging two list in a single array
{ 
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(; i<=mid;i++)//copy remaining elem from the firts list
        B[k++]=A[i];
    for(; j<=h;j++)//copy remaining elem frim the second bit of the list
        B[k++]=A[j];

    for(int i=l;i<=h;i++)//copy the sorted two lists from the auxiliary array B back to A
        A[i]=B[i];
}

void IMergeSort(int A[], int n)
{
    int p, i, l, mid,h;
    
    for(p=2;p<=n;p=p*2)//no. of passes O(nlogn) loop
    {
        for(i=0;i+p-1<n;i=i+p)//merging all the list in a single pass
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n)//handle odd no. of elem
        merge(A,0,p/2-1,n-1);

}
int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10, i;

IMergeSort(A,n);

for(i=0;i<n;i++)
 printf("%d ", A[i]);

printf("\n");


    return 0;
}
