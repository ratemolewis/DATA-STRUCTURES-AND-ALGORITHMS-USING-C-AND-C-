#include <stdio.h>
#include <stdlib.h>

struct Queue{
int size;
int front;
int rear;
int *q;
};

void create(struct Queue *Q, int size){

 Q->size=size;
 Q->front=Q->rear=-1;
 Q->q=(int*)malloc(size*sizeof(int));


}

void enqueue(struct Queue* Q, int x){
//check full condition
if(Q->rear==Q->size-1){
   printf("Queue overflow\n");
   return;
}else{
    Q->rear++;
    Q->q[Q->rear]=x;
}
}
int dequeue(struct Queue *Q){
   int x=-1;
   //check queue empty condition
   if(Q->front==Q->rear){
    printf("Queue underflow\n");
   }else{
    Q->front++;
    x=Q->q[Q->front];
   }
   return x;
}
void Display(struct Queue Q){
   //check empty condition
   int i=Q.front+1;
   if(Q.front==Q.rear){
    printf("Queue underflow\n");
    return;
   }else{
      for(i;i<=Q.rear;i++){
        printf("%d ",Q.q[i]);
      }
      printf("\n ");
   }
}
int main()
{
    struct Queue Q;
    create(&Q,5);

    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);


    Display(Q);
    printf("%d ", dequeue(&Q));
    printf("\n");
    Display(Q);
    return 0;
}
