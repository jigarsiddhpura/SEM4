#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ver 9

void initSingleSource(int distance[ver], bool path[ver], int source)
{
    for (int v = 0; v < ver; v++)
    {
        distance[v] = INT_MAX;
        path[v] = false;
    }
    distance[source] = 0;
}

int min_i(int distance[ver], bool path[ver]){
    int min = INT_MAX ,u;
    for (int v = 0; v < ver; v++)
    {
        if(distance[v]<min && path[v]==false){
            min = distance[v];
            u = v;
        }
    }
    return u;
}

void relax(int u,int v,int distance[ver],int parent[ver],bool path[ver], int graph[ver][ver]){
    if (graph[u][v] != 0 && path[v] == false && distance[v] > distance[u] + graph[u][v])
    {
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;
    }
}

void dijkstra(int source, int graph[9][9])
{
    int distance[9], parent[9] = {-1};
    bool path[9];

    initSingleSource(distance, path, source);
    int count = ver;
    while (count != 0)
    {
        int u = min_i(distance,path);
        path[u] = true;
        for (int v = 0; v < ver; v++)
        {
            relax(u,v,distance,parent,path,graph);
        }
        count--;
    }
        printf("\nvertex\tdistance from source\tparent");
    for (int i = 0; i < ver; i++)
    {
        printf("\n%d\t\t%d\t\t%d", i, distance[i], parent[i]);
    }
}

void main()
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
    int source = 3;
    dijkstra(source, graph);
}