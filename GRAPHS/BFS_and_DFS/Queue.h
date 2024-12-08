#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
#include <stdio.h>
//Queue implementation for BFS of graph traversal, which is similar 
//to level order traversal in tree traversals.
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is Full\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)//if this is the first node
            front=rear=t;
        else
        {
           rear->next=t;
           rear=t; 
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node* t;

    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        if(front==rear)
        {
            x=front->data;
            t=front;
            front=rear=front->next;
            
        }
        else
        {
            x=front->data;
            t=front;
            front=front->next;
        }
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}
#endif