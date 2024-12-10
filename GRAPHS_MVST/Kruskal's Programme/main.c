#include <stdio.h>
#include <stdlib.h>

#define I 32767
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

void Myunion(int u, int v) // weighted union
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) // collapsing find
{
    int x = u;
    while (set[x] > 0)
    {
        x = set[x];
    }
    while (u != x)
    {
        int v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

int include[9] = {0};
int t[2][6];
int i, j, k, u, v, min = I, n = 7, e = 9;

int main()
{
    i = 0;
    while (i < n - 1) // loop for number of edges in solution
    {
        min = I;

        for (j = 0; j < e; j++) // loop over the edges array
        {
            if (include[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if (find(u) != find(v)) // as long they have different parents // not forming a circle
        {
            t[0][i] = u;
            t[1][i] = v;
            Myunion(find(u), find(v));
            include[k] = 1;
            i++;
            printf("%d %d %d %d\n",u,v,find(u),find(v));
          }
          else
          {
            include[k]=1;
          }
    }
     printf("Spanning Tree\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d %d\n", t[0][i], t[1][i]);
    }

    return 0;
}
