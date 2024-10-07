#include <stdio.h>
#include <stdlib.h>
// double ended queue using an array
struct Deque
{
    int size;
    int front;
    int rear;
    int *Arr;
}*Deque;

// Initialize the deque with a dynamic array
void initDeque(struct Deque *dq, int size) {
    dq->Arr = (int *)malloc(size * sizeof(int));  // Allocate memory dynamically
    if (dq->Arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    dq->front = -1;
    dq->rear = -1;
    dq->size = size;
}

//check dequeu is full
int isFull(struct Deque *dp)
{
    return (dp->front==0&&dp->rear==dp->size-1)||(dp->rear+1==dp->front);
}

int isEmpty(struct Deque *dp)
{
    return dp->front==-1;
}

//insert an element at rear
void insertRear(struct Deque *dp, int x)
{
    if(isFull(dp))
    {
      printf("Deque is Full\n");
      return;
    }

    if(isEmpty(dp))
    {
        dp->front=0;
        dp->rear=0;
    }else{
        dp->rear=(dp->rear+1)%dp->size;
    }
    dp->Arr[dp->rear]=x;
    printf("%d inserted at rear\n", x);
}

void insertFront(struct Deque *dp, int x)
{
    if(isFull(dp))
    {
        printf("Deque is full\n");
        return;
    }

    if(isEmpty(dp))
    {
        dp->front=0;
        dp->rear=0;
    }else{
        dp->front=(dp->front-1+dp->size)%dp->size;//cirular array functionalty; flips the array from the end 
    }
    dp->Arr[dp->front]=x;
    printf("%d inserted at front\n",x);
}

void deleteFront(struct Deque *dp)
{
    if(isEmpty(dp))
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Element deleted from front: %d\n",dp->Arr[dp->front]);
    if(dp->front==dp->rear)
    {
        dp->front=-1;
        dp->rear=-1;
    }else{
        dp->front=(dp->front+1)%dp->size;//modulo for wrap-around
    }
    
}

void deleteRear(struct Deque *dp)
{
    if(isEmpty(dp))
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Element deleted from rear: %d",dp->Arr[dp->rear]);
    if(dp->front==dp->rear)
    {
        dp->front=dp->rear=-1;
    }else{
        dp->rear=(dp->rear-1+dp->size)%dp->size;
    }
}

int getFront(struct Deque *dp)
{
     if(isEmpty(dp))
     {
        printf("Deque is empty\n");
        return -1;
     }

     return dp->Arr[dp->front];
}

int getRear(struct Deque *dp)
{
     if(isEmpty(dp))
     {
        printf("Deque is empty\n");
        return -1;
     }

     return dp->Arr[dp->rear];
}

void freeDeque(struct Deque *dq)
{
    if(dq->Arr)
    {
        dq->Arr=NULL;
    }
}

int main()
{
   struct Deque dq;
   int size=5;

   initDeque(&dq, size);

   insertRear(&dq,5);
   insertRear(&dq,20);
   insertFront(&dq,30);

    printf("Front element: %d\n", getFront(&dq));
    printf("Rear element: %d\n", getRear(&dq));

    deleteFront(&dq);
    deleteRear(&dq);

    printf("After deletion, front element: %d\n", getFront(&dq));
    printf("After deletion, rear element: %d\n", getRear(&dq));

    freeDeque(&dq);  // Free the allocated memory at the end

    return 0;
}

