// Implement DFS and BFS on a graph.

#include <stdio.h>

int AdjacencyMatrix[10][10], visited[10], StartingVertex, vertices, ResultantQueue[10], Front = -1, Rear = -1;

void BFS(int StartingV)
{
    visited[StartingV] = 1;
    printf("%d\t", StartingV);
    for (int i = 1; i <= vertices; i++)
    {
        if (AdjacencyMatrix[StartingV][i] == 1 && !visited[i])
        {
            ResultantQueue[++Rear] = i;
            visited[i] = 1;
        }
    }
    if (Front < Rear)
    {
        BFS(ResultantQueue[++Front]);
    }
}

void DFS(int startingV)
{
    visited[startingV] = 1;
    printf("%d\t", startingV);
    for (int i = 1; i <= vertices; i++)
    {
        if (AdjacencyMatrix[startingV][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main(void)
{
    printf("Enter starting Vertex: ");
    scanf("%d", &StartingVertex);
    printf("Enter no. of vertices: ");
    scanf("%d", &vertices);
    for (int i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
    }
    for (int i = 1; i <= vertices; i++)
    {
        ResultantQueue[i] = 0;
    }
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= vertices; i++) 
    {
        for (int j = 1; j <= vertices; j++)
        {
            scanf("%d", &AdjacencyMatrix[i][j]);
        }
    }
    printf("BFS: ");
    BFS(StartingVertex);
    for (int i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
    }
    printf("\nDFS: ");
    DFS(StartingVertex);
    printf("\n");
    return 0;
}
