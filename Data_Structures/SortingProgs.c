#include <stdio.h>
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int smallest(int arr[], int k, int n)
{
    int pos = k, small = arr[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}
void selectionSort(int arr[], int n)
{
    int k, pos, temp;
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}
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
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
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
    int arr[20];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int choice;
    do
    {
        printf("Menu:\n1.Insertion Sort\n2.Selection Sort\n3.Quick Sort\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The sorted array is:\n");
                insertionSort(arr, n);
            break;

        case 2:
            printf("The sorted array is:\n");
                selectionSort(arr, n);
            printArray(arr, n);
            break;

        case 3:
            printf("The sorted array is:\n");
                quicksort(arr, 0, n - 1);
            printArray(arr, n);
            break;

        case 4:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}