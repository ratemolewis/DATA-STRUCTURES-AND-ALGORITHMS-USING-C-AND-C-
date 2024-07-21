#include <stdio.h>
#include <stdlib.h>
//Drawbacks solved for queue implementation using array;
 // 1.Spaces of deleted elements can't be used
  //2.Situation queue empty and full at the same time;
//Solution:
   // 1.Resetting front and rear pointer to -1 once the become equal, for usability of spaces
   // 2.Implement circular queue(the best choice);
//conditions:
    //empty-> if(front==rear).
    //full->if((rear+1)%size==front)

    struct Queue
    {
        int size;
        int front;
        int rear;
        int *Q;
    };

    void create(struct Queue *q, int size)
    {
       q->size=size;
       q->front=q->rear=0;
       q->Q=(int *)malloc(size*sizeof(int));
    }

    void enqueue(struct Queue *q, int x)
    {
        //check queue full condition
        if((q->rear+1)%q->size==q->front)
            printf("Queue is full\n");
        else
        {    //move rear pointer to the next place and add element.
            q->rear=(q->rear+1)%q->size;
            q->Q[q->rear]=x;
        }
    }

    int dequeue(struct Queue *q)
    {
        int x=-1;
        //check queue empty condition
        if(q->front==q->rear)
            printf("Queue is empty\n");
        else
        {
            //move front pointer and delete.
            q->front=(q->front+1)%q->size;
            x=q->Q[q->front];
        }
        return x;
    }
    void Display(struct Queue q)
    {
        //check empty condition
        if(q.front==q.rear)
            printf("Queue empty\n");
        else
        {
            int i=q.front+1;
           do
           {
               printf("%d\n",q.Q[i]);
               i=(i+1)%q.size;
           }while(i!=(q.rear+1)%q.size);

            }
    }
int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);


    Display(q);
    printf("%d\n",dequeue(&q));

    return 0;
}
