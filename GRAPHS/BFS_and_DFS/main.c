#include <stdio.h>
#include "Queue.h"

 void BFS(int G[][7], int start, int n)
 //T=O(n^2)
 //similar to level order traversal and uses a queue
 {
   int i=start,j;
   int visited[7]={0};

   printf("%d ",i);
   visited[i]=1;
   enqueue(i);

   while(!isEmpty())//Exploring all vertices
   {
     i=dequeue();
     for(j=1;j<n;j++)//visiting new vertices
     {
       if(G[i][j]==1 && visited[j]==0)//if there is an edge and its not visited
       {
         printf("%d ",j);
         visited[j]=1;
         enqueue(j);
       }
     }
   }
 }

void DFS(int G[][7],int start, int n)
//similar to preorder traversal of a tree and internal it uses a stack
//T=O(n)
{
  static int visited[7]={0};
  int j;

  if(visited[start]==0)
  {
     printf("%d ", start);
     visited[start]=1; //visiting a node

     for(j=1;j<n;j++)//exploring the adjacent vertice to the visited vertice
     {
      if(G[start][j]==1 && visited[j]==0)
      {
        DFS(G,j,n);
      }
     }
  }
}

int main()
{
   int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
//BFS(G,5,7);
DFS(G,1,7);

} 