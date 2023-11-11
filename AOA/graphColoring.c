#include <stdio.h>

#define NUM_VERTICES 5

int graph[NUM_VERTICES][NUM_VERTICES] = {
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

int colors[NUM_VERTICES] = {0};

int isSafe()
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        for (int j = i + 1; j < NUM_VERTICES; j++)
        {
            if (graph[i][j] == 1 && colors[i] == colors[j])
                return 0;
        }
    }
    return 1;
}

int graphColoring(int numColors, int vertexIndex)
{
    if (vertexIndex == NUM_VERTICES)
    {
        if (isSafe() == 1)
        {
            for (int j = 0; j < NUM_VERTICES; j++)
            {
                printf("Vertex %d : %d\n", j, colors[j]);
            }
            return 1;
        }
        return 0;
    }
    
    for (int color = 1; color <= numColors; color++)
    {
        colors[vertexIndex] = color;
        if (graphColoring(numColors, vertexIndex + 1) == 1)
            return 1;
        // colors[vertexIndex] = 0;
    }
    return 0;
}

int main()
{
    int numColors = 3;
    int source = 0;
    graphColoring(numColors, source);
    
    return 0;
}
