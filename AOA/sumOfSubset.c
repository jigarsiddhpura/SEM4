#include <stdio.h>

int subsetArray[100];

void printSubset(int elements[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", subsetArray[i]);
    }
    printf("{ ");
    for (int i = 0; i < size; i++)
    {
        if (subsetArray[i] == 1)
        {
            printf("%d ", elements[i]);
        }
    }
    printf("}");
}

void sumOfSubset(int currentSum, int index, int remainingSum, int elements[], int targetSum, int size)
{
    subsetArray[index] = 1;
    if (currentSum + elements[index] == targetSum)
    {
        printSubset(elements, size);
    }
    else if (currentSum + elements[index] + elements[index + 1] <= targetSum)
    {
        sumOfSubset(currentSum + elements[index], index + 1, remainingSum - elements[index], elements, targetSum, size);
    }

    //  Checks if excluding the current element and considering the remaining elements can still achieve the target sum
    if (currentSum + (remainingSum - elements[index]) >= targetSum && currentSum + elements[index + 1] <= targetSum)
    {
        for (int i = index; i < size; i++)
        {
            subsetArray[i] = 0;
        }
        sumOfSubset(currentSum, index + 1, remainingSum - elements[index], elements, targetSum, size);
    }
}

int main()
{
    int elements[] = {2, 3, 5, 6, 8, 10};
    int targetSum = 10;
    int size = sizeof(elements) / sizeof(elements[0]);
    int remainingSum = 0;
    for (int i = 0; i < size; i++)
    {
        remainingSum += elements[i] ;
    }
    
    printf("Possible subsets:\n");
    for (int i = 0; i < size; i++)
    {
        printf("x%d\t", i + 1);
    }
    
    sumOfSubset(0, 0, remainingSum, elements, targetSum, size);
    
    return 0;
}
