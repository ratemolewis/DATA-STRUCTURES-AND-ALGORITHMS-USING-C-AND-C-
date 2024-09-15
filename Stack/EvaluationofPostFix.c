#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=(struct Mode *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack is Empty\n");
    }else{
        t->data=x;
        t->next=top;
        top=t;
        }
}

int pop(){
    int x=-1;
    struct Node *t;
    if(top==NULL){
        printf("Stack is empty\n");
    }else {
        t=top;
        x=t->data;
        top=top->next;
        free(t);
        }
        return x;
}

void Display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int isOperand(int x){
    if(x=='+'||x=='-'||x=='/'||x=='*'){
        return 0;
    }else{
        return 1;
    }
}
int Eval(char *postfix){
    int i;
    int x1, x2, r;
    for(i=0; postfix[i]!='\0'; i++){
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else{
            x2=pop();x1=pop();
            switch(postfix[i]){
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix="234*+82/-";

    printf("Result is %d\n", Eval(postfix));
    return 0;
}
