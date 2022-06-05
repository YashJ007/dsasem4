#include <stdio.h>
int n, v;
int a[100][100];
int vis[100];
int f = -1, r = -1;
int q[100];

void BFS(int v)
{
    printf("%d ", v);
    vis[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && !vis[i])
        {
            q[++r] = i;
            vis[i] = 1;
        }
    }

    if (f < r)
    {
        BFS(q[++f]);
    }
}

void DFS(int v)
{
    vis[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && !vis[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nAdjacency matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    v = 0;
    printf("\n\n BFS : ");
    BFS(v);

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    v = 0;
    printf("\n\n DFS : ");
    DFS(v);

    return 0;
}