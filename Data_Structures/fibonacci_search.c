// ONLY FOR SORTED ARRAYS
#include <stdio.h>

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int x, int n)
{
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM1 + fibM2;

    // fibM is greatest fibonacci number less than n
    while (fibM < n)
    {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibM2, n - 1);  
        if (arr[i] < x)
        // left shift by 1 & change offset 📌
        {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }

        else if (arr[i] > x)
         // left shift by 2 📌
        {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }

        else
            return i;
    }

    if (fibM1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

void main()
{
    int arr[50], size, i, x, index;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d - ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    index = fibonacciSearch(arr, x, size);
    if (index >= 0)
    {
        printf("%d is at index %d", x, index);
    }
    else
    {
        printf("%d isn't present in the array", x);
    }
}