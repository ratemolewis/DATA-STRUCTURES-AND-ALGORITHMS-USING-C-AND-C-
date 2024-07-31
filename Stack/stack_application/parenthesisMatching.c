#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
      printf("Stack full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }

}
char pop()
{
    struct Node  *t;
    char x=-1;
    if(isEmpty())
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
    p=top;
    if(isEmpty())
        printf("Stack empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p=p->next;
        }
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
    //before popping check first if there is anything is stack
           if(top==NULL)
                return 0;
            pop();
        }
    }
    //check at last if the stack is empty
    if(top==NULL)
        return 1;
    else
        return 0;
}
 int isEmpty()
 {
    return top?0:1;
 }
int main()
{
    char *exp="(((a+b)*(c-d)))";
    printf("%d ",isBalanced(exp));
    printf("Hello world!\n");
    return 0;
}
