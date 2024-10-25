#include <stdio.h>
#include <stdlib.h>
//this solves the drawback of deletion in a single pointer queue(O(n)):
    //full condition -> if(rear==size-1).
   // empty condition -> if(front==rear).
//time complexity:
    //enqueue and dequeue -> O(1)/constant tim

struct Queue
{
    int size;
    int front;
    int rear;
    int* Q;
};
void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(size*sizeof(int));
}
void enqueue(struct Queue *q, int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{   int x=-1;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];

    }
    return x;
}

void Display(struct Queue q)
{    int i;
    if(q.front==q.rear)
        printf("Queue is empty\n");
    else
    {
        for(i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;


    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    Display(q);

    printf("%d \n",dequeue(&q));
    Display(q);
    return 0;
}
