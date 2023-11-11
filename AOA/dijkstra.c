#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define ver 9

void initialiseSingleSource(int distance[], bool path[], int source)
{
    for (int v = 0; v < 9; v++)
    {
        distance[v] = INT_MAX;
        path[v] = false;
    }
    distance[source] = 0;
}

int minDistance(int distance[], bool path[])
{
    int min = INT_MAX, u;
    for (int v = 0; v < 9; v++)
    {
        if (path[v] == false && distance[v] <= min)
        {
            min = distance[v];
            u = v;
        }
    }
    return u;
}

void relax(int u, int v, int distance[], int parent[], bool path[], int graph[9][9])
{
    if (graph[u][v] != 0 && path[v] == false && distance[v] > distance[u] + graph[u][v])
    {
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;
    }
}

int dijkstra(int graph[9][9], int source)
{
    int distance[9], parent[9] = {-1};
    bool path[9];

    int vertex = ver;
    initialiseSingleSource(distance, path, source);
    while (vertex != 0)
    {
        int u = minDistance(distance, path);
        path[u] = true;
        for (int v = 0; v < 9; v++)
        {
            relax(u, v, distance, parent, path, graph);
        }

        vertex--;
    }


    printf("\nvertex\tdistance from source\tparent");
    for (int i = 0; i < 9; i++)
    {
        printf("\n%d\t\t%d\t\t%d", i, distance[i], parent[i]);
    }

    return 0;
}

int main()
{
    int graph[9][9] = {{0, 11, 0, 0, 0, 0, 0, 8, 0},
                       {0, 0, 8, 0, 0, 0, 0, 7, 0},
                       {0, 0, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 0, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 9, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int source = 0;
    dijkstra(graph, source);
    return 0;
}


