#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define VERTEX_COUNT 5

void initialiseSingleSource(int distance[], int source)
{
    for (int v = 0; v < VERTEX_COUNT; v++)
    {
        distance[v] = INT_MAX;
    }
    distance[source] = 0;
}

void relax(int u, int v, int distance[], int parent[], int graph[VERTEX_COUNT][VERTEX_COUNT])
{
    if (graph[u][v] != 0 && distance[v] > distance[u] + graph[u][v])
    {
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;
    }
}

int bellman(int graph[VERTEX_COUNT][VERTEX_COUNT], int source)
{
    int distance[VERTEX_COUNT], parent[VERTEX_COUNT] = {-1};
    initialiseSingleSource(distance, source);

    for (int i = 0; i < VERTEX_COUNT - 1; i++)               // ⭐⭐
    {
        for (int u = 0; u < VERTEX_COUNT; u++)
        {
            for (int v = 0; v < VERTEX_COUNT; v++)
            {
                relax(u, v, distance, parent, graph);
            }
        }
    }

    for (int u = 0; u < VERTEX_COUNT; u++)
    {
        for (int v = 0; v < VERTEX_COUNT; v++)
        {
            if (graph[u][v] != 0 && distance[v] > distance[u] + graph[u][v])
            {
                printf("Negative cycle detected!\n");
                return 0;
            }
        }
    }

    int route[VERTEX_COUNT], index = 0;
    int start, end;
    printf("Enter Start vertex:");
    scanf("%d", &start);
    printf("Enter end vertex:");
    scanf("%d", &end);

    if (start < 0 || start >= VERTEX_COUNT || end < 0 || end >= VERTEX_COUNT)
    {
        printf("Invalid start or end vertex!\n");
        return 0;
    }

    do
    {
        route[index] = end;
        int pr = parent[end];
        end = pr;
        index++;
    } while (end != start);
    route[index] = start;

    printf("Path: ");
    for (int i = index; i >= 0; i--)
    {
        printf("%d ", route[i]);
        if (i != 0)
            printf("-> ");
    }
    printf("\n");

    parent[source] = -1;

    printf("Vertex\tDistance from Source\tParent\n");
    for (int i = 0; i < VERTEX_COUNT; i++)
    {
        printf("%d\t%d\t\t\t%d\n", i, distance[i], parent[i]);
    }

    return 1;
}

int main()
{
    int graph[VERTEX_COUNT][VERTEX_COUNT] = {{0, 6, 0, 7, 0},
                                             {0, 0, 5, 8, -4},
                                             {0, -2, 0, 0, 0},
                                             {0, 0, -3, 0, 9},
                                             {2, 0, 7, 0, 0}};
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

        if (source < 0 || source >= VERTEX_COUNT)
    {
        printf("Invalid source vertex!\n");
        return 0;
    }

    bellman(graph, source);
    return 0;
}

