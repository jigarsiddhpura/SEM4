#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int m = mid - low + 1;
    int n = high - mid;
    int arr1[m], arr2[n];

    for (int i = 0; i < m; i++)
    {
        arr1[i] = arr[low + i];
    }
    for (int j = 0; j < n; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    int i, j, k;
    i = j = 0;
    k = mid;

    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else 
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        // arr[i] = rand() % n;
    }

    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    double duration = ((double)end - start);
    printf("Time by mergeSort : %f\n", duration);
}