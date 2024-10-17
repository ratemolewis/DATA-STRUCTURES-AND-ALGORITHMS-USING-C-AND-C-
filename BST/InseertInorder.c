#include <stdio.h>
#include <stdlib.h>

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

void Inorder(struct Node *p)//recursive function
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

int main()
{
    struct Node *temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    printf("\n");

    temp=Search(2);
    if(temp)
        printf(" The element %d is found",temp->data);
    else
        printf("The element is not found");
    

}