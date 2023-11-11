#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{

    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{

    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void main()
{
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    int randArr[n];
    for (i = 0; i < n; i++)
    {
        randArr[i] = rand() % n;
        // randArr[i] = n-i;
    }
    
    clock_t start, end;

    start = clock();
    insertionSort(randArr, n);
    end = clock();
    double duration = ((double)end - start) ;
    printf("Time by insertion sort : %f\n", duration);

    start = clock();
    selectionSort(randArr, n);
    end = clock();
    duration = ((double)end - start) ;
    printf("Time by selection sort : %f\n", duration);
}