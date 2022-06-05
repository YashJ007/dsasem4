#include <stdio.h>

void prims(int n, int cost[10][10])
{
    int min_cost = 0, min;
    int e = 1, u = 1, v = 1;
    int visited[10];

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    visited[1] = 1;

    while (e < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)
                    {
                        continue;
                    }
                    else
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
            if (visited[u] == 0 || visited[v] == 0)
            {
                min_cost = min_cost + min;
                printf("\n%d ) edge(%d, %d) and cost = %d", e++, u, v, min);
                visited[v] = 1;
            }
            cost[u][v] = cost[v][u] = 999;
        }
    }
    printf("\n Min Cost = %d", min_cost);
}

int main()
{
    int n, cost[10][10];

    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("cost[%d][%d] = ", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    prims(n, cost);
}

/*
0
1
4
1
0
9
4
9
0

*/