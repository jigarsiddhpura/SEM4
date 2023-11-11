#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return (i);
}
void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}
void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 1; i < n; i++)
    {
        arr[i] = rand() % i;
    }

    clock_t start , end;
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    double duration = ((double)end - start);
    printf("Time by quicksort : %f\n", duration);
}