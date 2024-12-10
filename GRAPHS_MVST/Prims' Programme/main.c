#include <stdio.h>
#include <stdlib.h>
#define I 65535
// this algorithm can be made fasterbuy using a rebblack tree or heap to find the minimum cost, T=O(nlogn)
//not useful for non-connected graph, one component
int cost[][8]=
{{I,I,I,I,I,I,I,I},
{I,I,25,I,I,I,5,I},
{I,25,I,12,I,I,I,10},
{I,I,12,I,8,I,I,I},
{I,I,I,8,I,16,I,14},
{I,I,I,I,16,I,20,18},
{I,5,I,I,I,20,I,I},
{I,I,10,I,14,18,I,I}};
     
int near[8]={I,I,I,I,I,I,I,I};
int t[2][6];
int main()
{
  int i,j,k,u,v,min=I,n=7;

  for(i=1; i<=n;i++)//find the minimum cost from cost adjacency mattix 
  {
    for(j=i;j<=n;j++)
    {
      if(cost[i][j]<min)
      {
        min=cost[i][j];
        u=i;v=j;
      }
    }
  }
  t[0][0]=u;//write in the soln array
  t[1][0]=v;
  near[u]=near[v]=0;//mark the vertices as selected

  for(i=1;i<=n;i++)//update the near array, whether the elements are near to v or u
  {
    if(near[i]!=0)
    {
      if(cost[i][u]<cost[i][v])
         near[i]=u;
      else
          near[i]=v;
    }
    
  }

  //now the repeating part of the algo:
  for(i=1;i<n-1;i++)
  {
    min=I;
    for(j=1;j<=n;j++)//find the minimum and connected edge
    {
      if(near[j]!=0&&cost[j][near[j]]<min)
      {
        min=cost[j][near[j]];
        k=j;
      }
    }
    t[0][i]=k;//update selected edge
    t[1][i]=near[k];
    near[k]=0;

    //update the near array, whether they are near to 'k' or they maintain
    for(j=1;j<=n;j++)
    {
      if(near[j]!=0&&cost[j][k]<cost[j][near[j]])
        near[j]=k;
    }
  }

  for(i=0;i<n-1;i++)
   printf("%d %d\n",t[0][i],t[1][i]);
}