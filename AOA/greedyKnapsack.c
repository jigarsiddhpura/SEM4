#include <stdio.h>

void main()
{
    float profits[100], weights[100], profitWeightRatio[100], knapsack[100], totalProfit = 0, totalWeight, maxRatio = 0;
    int i, j, numElements, visited[100], maxIndex;

    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    for (i = 0; i < numElements; i++)
    {
        printf("Enter the profit and weight of element %d: ", i + 1);
        scanf("%f %f", &profits[i], &weights[i]);
        profitWeightRatio[i] = profits[i] / weights[i];
        visited[i] = 0;
    }

    printf("Enter the total weight: ");
    scanf("%f", &totalWeight);

    while (totalWeight != 0)
    {
        maxRatio = 0;
        for (j = 0; j < numElements; j++)
        {
            if (visited[j] == 0 && profitWeightRatio[j] > maxRatio)
            {
                maxRatio = profitWeightRatio[j];
                maxIndex = j;
            }
        }

        visited[maxIndex] = 1;

        if (weights[maxIndex] <= totalWeight)
        {
            totalWeight -= weights[maxIndex];
            knapsack[maxIndex] = 1;
        }
        else
        {
            knapsack[maxIndex] = totalWeight / weights[maxIndex];
            totalWeight = 0;
        }

        totalProfit += knapsack[maxIndex] * profits[maxIndex];
    }

    printf("\nProfit\t\tWeight\t\tP/W Ratio\tKnapsack\n");
    for (i = 0; i < numElements; i++)
    {
        printf("%f\t%f\t%f\t%f\n", profits[i], weights[i], profitWeightRatio[i], knapsack[i]);
    }
    printf("Max profit is %f\n", totalProfit);
}
