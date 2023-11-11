#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

void primMST(int source)
{
    int parent[SIZE];       // Array to store constructed MST
    int weights[SIZE];          // weights values used to pick the minimum weight edge
    bool visited[SIZE];      // To track vertices included in MST

    // Initialize all weightss as infinite and visited as false
    for (int i = 0; i < SIZE; i++)
    {
        weights[i] = INT_MAX;
        visited[i] = false;
    }

    // Always include the specified source vertex in MST
    weights[source] = 0;
    parent[source] = -1;    // First node is always the root of MST

    for (int count = 0; count < SIZE - 1; count++)
    {
        // Find the vertex with the minimum weights value from the set of vertices not yet included in MST
        int minweights = INT_MAX;
        int minIndex = -1;
        for (int v = 0; v < SIZE; v++)
        {
            if (visited[v] == false && weights[v] < minweights)
            {
                minweights = weights[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST set
        visited[minIndex] = true;

        // Update weights values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < SIZE; v++)
        {
            if (graph[minIndex][v] && visited[v] == false && graph[minIndex][v] < weights[v])
            {
                parent[v] = minIndex;
                weights[v] = graph[minIndex][v];
            }
        }
    }

    // Print the constructed MST
    printf("Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < SIZE; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, weights[i]);
    }
}

int main()
{
    int source = 0;
    primMST(source);

    return 0;
}
