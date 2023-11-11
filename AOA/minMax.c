#include <stdio.h>

struct pair
{
    int min;
    int max;
} minMax;

struct pair getMinMax(int arr[], int n)
{
    /*If there is only one element then return it as min and max both*/
    if (n == 1)
    {
        minMax.max = arr[0];
        minMax.min = arr[0];
        return minMax;
    }
    /* If there are more than one elements, then initialize min and max*/
    if (arr[0] > arr[1])
    {
        minMax.max = arr[0];
        minMax.min = arr[1];
    }
    else
    {
        minMax.max = arr[1];
        minMax.min = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] < minMax.min)
        {
            minMax.min = arr[i];
        }
        else if (arr[i] > minMax.max)
        {
            minMax.max = arr[i];
        }
    }

    return minMax;
}

void main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    struct pair ans = getMinMax(arr, arr_size);
    printf("Minimum element is %d", minMax.min);
    printf("\nMaximum element is %d", minMax.max);
}