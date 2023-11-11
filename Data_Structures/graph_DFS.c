#include <stdio.h>
#include <conio.h>
int adj_mat[20][20], visited[20], n;
void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 1; i <= n; i++)
        if (adj_mat[v][i] && !visited[i])
        {
            DFS(i);
        }
}

void main()
{
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for (j = 1; j <= n; j++)
            adj_mat[i][j] = 0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj_mat[i][j]);
    DFS(1);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
}