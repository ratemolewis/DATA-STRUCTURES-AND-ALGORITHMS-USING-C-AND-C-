#include <stdio.h>
#include <stdlib.h>
//time complexity of all the operations is O(1);
//conditions:
    //full-> if (top=size-1).
    //empty-> If(top=-1).

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size of stack");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}
void push(struct Stack *st, int x)
{
    //check full condition
    if(st->top==st->size-1)
        printf("Stack overflow\n");

   else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
void Display(struct Stack st)
{
    int i;
    if(st.top==-1)
        printf("Stack is empty\n");

    else
    {
        for(i=st.top;i>=0;i--)
        {
            printf("%d ", st.S[i]);
        }

    }
    printf("\n");
}

int pop(struct Stack *st)
{
    int x=-1;
    //check if the stack is empty
    if(st->top==-1)
        printf("Stack underflow\n");

    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int x=-1;
    //check if the index is valid.
    if(st.top-pos+1<0)
        printf("Position is invalid\n");

    else
    {
        x=st.S[st.top-pos+1];
    }
    return x;
}

int stackTop(struct Stack st)
{

    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;

        return 0;
}

int isFull(struct Stack st)
{
    return (st.top==st.size-1);

}

int main()
{
    struct Stack st;
     create(&st);

     push(&st,10);
     push(&st,20);
     push(&st,30);
     push(&st,40);



     printf("%d\n",peek(st,4));

     Display(st);

    return 0;
}
