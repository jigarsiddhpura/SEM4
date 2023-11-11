#include <stdio.h>

struct node
{
    int dist[20];
    int from[20];
} routingTable[10];

void main()
{
    int nodes, costMat[20][20], i, j;

    printf("\nEnter the number of nodes : ");
    scanf("%d", &nodes);
    printf("\nEnter the cost matrix :\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            printf("Cost of (%d,%d) : ", i, j);
            scanf("%d", &costMat[i][j]);
            costMat[i][i] = 0;
            routingTable[i].dist[j] = costMat[i][j];
            routingTable[i].from[j] = j;
        }
    }

}