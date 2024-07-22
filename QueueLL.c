#include <stdio.h>
#include <stdlib.h>
//Queue is a logical data stracturer implemented using nodes of a linked list.
//constant:
   // initially: rear and front pointers are NULL.
    //special case: upon first node(t) creation->front and rear pointers should be moved to "t".
//conditions:
   // empty-> if either front or rear is equal to null. if(front==NULL) or if(rear==NULL).
   // full->if i can't create node from heap. Node *t=new Node; if(t==NULL).
   //both insertion and deletion is O(1)
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    //check full condition
    if(t==NULL)
        printf("Queue is full\n");
    else
    {
        t->data=x;
        t->next=NULL;
        //if this it the first node set front and rear pointer upon it.
        if(front==NULL)
            front=rear=t;
        else
        {
          rear->next=t;
          rear=t;
        }
    }
}

int dequeue(struct Node *p)
{
    int x;
    struct Node *t;
    //check if queue is empty
    if(front==NULL)
        printf("Queue is empty\n");
    else
    {
        t=front;
        x=front->data;
        front=front->next;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }

}

int main()
{
   struct Node *q;
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);

   dequeue(&q);

   Display();

    printf("Hello world!\n");
    return 0;
}
