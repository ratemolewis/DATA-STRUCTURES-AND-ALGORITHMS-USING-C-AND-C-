#include <stdio.h>
#include <stdlib.h>
//implementation of stack using linked list, with time complexity of 'O(1)'.
//conditions:
    //empty-> if(top==NULL).
    //full-> struct Node *t=new Node; if(t==NULL)

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    // this also works for first node creation.
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    //check full condition
    if(t==NULL)
        printf("Stack full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    int x=-1;
    struct Node *t;
    //check empty condition
    if(top==NULL)
        printf("Stack empty\n");
    else
    {
        t=top;
        x=top->data;
        top=top->next;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    //check empty condition
    if(top==NULL)
    printf("Stack empty\n");
    else
    {
        p=top;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\n");
}

int peek(int pos)
{
    struct Node *p;
    int i=0;
    //check empty condition
    if(top==NULL)
        printf("Stack empty\n");
    else
    {
        p=top;
        for(i;p!=NULL && i< pos-1; i++)
        {
            p=p->next;
        }
        if(p!=NULL)
            return p->data;
        else
            return -1;
    }
}
int stackTop()
{
    if(top)
        return top->data;
    return -1;
}

int isEmpty()
{
    return top?0:1;
}

int isFull()
{
 struct Node *t;
 t=(struct Node *)malloc(sizeof(struct Node));
   int r=t?0:1 ;
   free(t);
   return r;

}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);


    //printf("%d\n",pop());
    //printf("%d\n",pop());
    //printf("%d\n",pop());
    printf("%d\n",isFull());
    Display();
    printf("Hello world!\n");
    return 0;
}
