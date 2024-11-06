#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//#include "Queue.h" 
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

void Stackpush(struct Stack *st, struct Node *x)
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

struct Node *Stackpop(struct Stack *st)
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

struct Node *Stacktop(struct Stack *stk)
{
    if(stk->top)
    {
        return stk->S[stk->top];
    }
    return NULL;
}

int isFullStack(struct Stack *st)
{
    return st->top==st->size-1;
}

int isEmptyStack(struct Stack *st)
{
    return st->top==-1;
}

#endif#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <limits.h>  // For INT_MAX

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;


void Insert(int key)
{  struct Node *t=root;
   struct Node *r=NULL,*p;

    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;//terminate function after first root initialization
    }

    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data) 
            t=t->rchild;
        else
            return;//if the element is equal to to the key; terminate

    }
       //create the root node to be inserted
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;  

        if(key<r->data) r->lchild=p;//check which side either left or right side for insertion
        else r->rchild=p;
        
}

struct Node * RInsert(struct Node *p, int key)
{
    struct Node *t;
    
    if(p==NULL)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
     if(key < p->data)
        p->lchild=RInsert(p->lchild, key);
     else if(key > p->data)
        p->rchild=RInsert(p->rchild,key);
        
        return p;
}

void Inorder(struct Node *p)//recursive ftunction
{
    if(p)//if p becomes 0, then terminate
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }

}
struct Node * Search(int key)
{
    struct Node *p=root;

    while(p)//
    {
    if(key==p->data)
        return p;
    else if(key<p->data)
        p=p->lchild;
    else
        p=p->rchild;
    }
    return NULL;// when the element is not found
   
}

int Height(struct Node *p)
{  int x, y;
    if(p==NULL)//stoping condition.
        return 0;//when we reach the leaf node, return 

   x=Height(p->lchild);
   y=Height(p->rchild);
  // if(x>y) return x+1;else return y+1;
  return x>y?x+1:y+1;

}

struct Node *InPre(struct Node *p)
{
     while(p && p->rchild!=NULL)
        p=p->rchild;

    return p;
}

struct Node *InSucc(struct Node *p)
{
     while(p && p->lchild!=NULL)
        p=p->lchild;

    return p;
}

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)//if p has become NULL, stop the process/delete
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)//delete this node,
    {
        if(p==root)
            root=NULL;
        free(p);// this is were delete is done, when we reach the leaf node.
        return NULL;
    }

    if(key<p->data)
        p->lchild=Delete(p->rchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

void createPre(int pre[], int n)//Generating BST from preorder
{ //for generating both inorder or postorder traversal we do not inorder for the tree creation; however, the difference
  //is that fro the post scanning of the array is done from the end, while the other from the front.
    struct Stack *stk;
    struct Node *t,*p;
    int i=0;
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;

    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Stackpush(stk,p);
            p=t;
        }
        else{
            //if(pre[i]>p->data && pre[i]<Stacktop(stk)->data)//if the element is within the range of the current p position and last p position contained at the stack top
            if (pre[i] > p->data && (Stacktop(stk) == NULL || pre[i] < Stacktop(stk)->data))
            {//create a node and join it a the right child of the node.
                t=(struct Node*)malloc(sizeof(struct Node));
                t->data=pre[i++];//after inserting increament i to pick the next element in array
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }else{
                p=Stackpop(stk);//otherwise pop and assign the previous address of pfrom the stack
            }
        }
    }

}


// THIS FUNCTION HANDLES THE STACK EMPTY CONDITION USING A MAXVALUE
// void createPre(int pre[], int n) {
//     struct Stack *stk;
//     struct Node *t, *p;
//     int i = 0;
//     int maxValue = INT_MAX;  // Initial max value set to "infinity"

//     root = (struct Node*)malloc(sizeof(struct Node));
//     root->data = pre[i++];
//     root->lchild = root->rchild = NULL;
//     p = root;

//     while (i < n) {
//         if (pre[i] < p->data) {
//             // Left child case
//             t = (struct Node*)malloc(sizeof(struct Node));
//             t->data = pre[i++];
//             t->lchild = t->rchild = NULL;
//             p->lchild = t;
//             Stackpush(stk, p);
//             p = t;
//         } else {
//             // Right child case with maxValue constraint
//             if (pre[i] > p->data && pre[i] < maxValue) {
//                 t = (struct Node*)malloc(sizeof(struct Node));
//                 t->data = pre[i++];  // Increment i to pick the next element in array
//                 t->lchild = t->rchild = NULL;
//                 p->rchild = t;
//                 p = t;
//             } else {
//                 // Update maxValue when popping from stack
//                 p = Stackpop(stk);
//                 maxValue = (p != NULL) ? p->data : INT_MAX;
//             }
//         }
//     }
// }


int main()
{
    struct Node *temp;
    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);

    Delete(root,50);
    Inorder(root);
    printf("\n");

    temp=Search(2);
    if(temp)
        printf(" The element %d is found",temp->data);
    else
        printf("The element is not found");
    

}