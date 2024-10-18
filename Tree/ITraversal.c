#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Queue.h" 
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st, int size)
{
    st->size=size;
    st->top=-1;
    st->S=(struct Node**)malloc(st->size*sizeof(struct Node*));
    if(st->S==NULL)
    {
        printf("Memory allocation failed for address pointer array\n");
         return;
    }
}

void push(struct Stack *st, struct Node *x)
{
    if(st->top==st->size-1) //Queue full condition
    {
        printf("Stack overflow\n");
        return;
    }else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x=NULL;
    if(st->top==-1) //stack empty condition
    {
        printf("Stack underflow\n");
        return x;
    }else{
        x=st->S[st->top--];
    }
    return x;
}

int isFullStack(struct Stack *st)
{
    return st->top==st->size-1;
}

int isEmptyStack(struct Stack *st)
{
    return st->top==-1;
}

#endif
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>  // Added stdlib.h for malloc()

// Structure for a tree node
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// This queue is storing members of a tree node
struct Queue {
    int front;
    int rear;
    int size;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size+1;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
    if (q->Q == NULL) {
            printf("Memory allocation failed for address pointer array\n");
             return;
         }
}

void enqueue(struct Queue *q, struct Node *x)
{
    // Check if queue is full
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    // Check if queue is empty
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
#endif // QUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h" 
#include "Stack.h" 

struct Node *root;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;  // Declare queue
    create(&q, 100);  // Initialize the queue

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node*)malloc(sizeof(struct Node));
    if (root == NULL) {
        printf("Memory allocation failed for root node\n");
        return;
    }

    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);  // Enqueue the root

    while (!isEmpty(q))  // While the queue is not empty
    {
        p = dequeue(&q);  // Dequeue node
        
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)  // If left child exists
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            if (t == NULL) {
                printf("Memory allocation failed for left child\n");
                return;
            }
            t->data = x;  // Assign value to left child
            t->lchild = t->rchild = NULL;
            p->lchild = t;  // Link left child
            enqueue(&q, t);  // Enqueue left child
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)  // If right child exists
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            if (t == NULL) {
                printf("Memory allocation failed for right child\n");
                return;
            }
            t->data = x;  // Assign value to right child
            t->lchild = t->rchild = NULL;
            p->rchild = t;  // Link right child
            enqueue(&q, t);  // Enqueue right child
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);  // Print node data
        Preorder(p->lchild);  // Traverse left subtree
        Preorder(p->rchild);  // Traverse right subtree
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
} 

void Postorder(struct Node *p)
{
      if(p)
      {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
      }
}

void IPreorder(struct Node *p)
{  //for the conversion of the above recursive functions to iterative; we need a stack
    struct Stack stk; //stack object
    Stackcreate(&stk,100);
    while(!isEmptyStack(&stk)||p)
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk,p);
            p=p->lchild;
        }else{
            p=pop(&stk);
            p=p->rchild;
        }
    }

}

int main()
{
    Treecreate();  // Create the tree
    printf("Preorder Traversal: ");
    IPreorder(root);  // Preorder traversal of the tree
    return 0;
}