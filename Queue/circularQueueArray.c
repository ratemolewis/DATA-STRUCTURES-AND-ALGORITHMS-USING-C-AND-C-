#include <stdio.h>
#include <stdlib.h>

//implementation of a circular queue to overcome the
//drawbacks of a normal double pointer queue.

struct Queue{
int size;
int front;
int rear;
int *Q;

};

void create(struct Queue* q,int size){
 q->size=size;
 //for circular queue front and rear both start from 0;
 q->front=q->rear=0;
 q->Q=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x){
  //check queue full condition
  if((q->rear+1)%q->size==q->front)
    printf("Queue overflow\n");
  else{
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
  }
}

int dequeue(struct Queue *q){
    //check queue empty condition
    int x=-1;
    if(q->front==q->rear){
        printf("Queue underflow\n");
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }

    return x;
}

void Display(struct Queue q){
    int i=q.front+1;
     do{
        printf("%d ", q.Q[i]);
        i=(i+1)%q.size;
     }while(i!=(q.rear+1)%q.size);

    printf("\n");
}

int main()
{
    struct Queue q;

    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    Display(q);


    printf("%d\n", dequeue(&q));
    Display(q);
    return 0;
}
