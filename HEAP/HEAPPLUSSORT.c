#include <stdlib.h>
#include <stdio.h>

void Insert(int H[],int n)
{
    int temp, i=n;
    ;//the iterative index
    temp=H[i];//take the element to be placed in heap
    while(i>1 && temp>H[i/2])//compare element with parent
    {
        H[i]=H[i/2];//copy parent to the left child position
        i=i/2;
    }
    H[i]=temp;//add the element at the heap
}

int Delete(int A[], int n)
{
    int x,i,j,temp,val;
    val=A[1];//deleted val
    x=A[n];
    A[1]=x;//copy the last element to first position
    A[n]=val;
    i=1, j=2*i;

    while(j<n-1)//as we have reduced one element, we subtract 1
    {
     if(A[j+1]>A[j])
        j=j+1;
     if(A[j]>A[i])
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i=j;// bring i on the child"j"
        j=2*j;//move to the left child 
    }else
        break;
    }
    return val;
}

int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2; i<=7;i++)
    Insert(H,i);

    // printf("Deleted value is %d\n",Delete(H,7));
    // printf("Deleted value is %d\n",Delete(H,6));
    for(i=7;i>1;i--)
    {
        Delete(H,i);//after deletion it makes a heapsort
    }
    
    for(i=1;i<=7;i++)
    printf("%d ", H[i]);//elemets are fprming a max heap
    printf("\n");

    
    
    return 0;
}