#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Stack full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;

    }
}

char pop()
{
    char x=-1;
    struct Node *t;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *t;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else{
        t=top;
        while(t!=NULL){
            printf("%c ",t->data);
            t=t->next;
        }
    }

    printf("\n");
}

int isEmpty()
{
    return top?0:1;
}

int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    return 0;
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
        return 1;
}
 char * InToPost(char *infinix)
 {

     char *postfix;
     int len=strlen(infinix);
     int  i=0,j=0;

     postfix=(char *)malloc((len+2)*sizeof(char));
     while(infinix[i]!='\0')
     {
         if(isOperand(infinix[i]))
            postfix[j++]=infinix[i++];
         else{
            if(pre(infinix[i])>pre(top->data))
                push(infinix[i++]);
            else{
                postfix[j++]=pop();
            }
         }
     }
     while(top!=NULL)
     {
         postfix[j++]=pop();
     }
     postfix[j]='\0';
     return postfix;
 }
int main()
{
    char *infinix="a+b*c";
    push('#');

    char *postfix=InToPost(infinix);


    printf("%s ", postfix);
    return 0;
}

