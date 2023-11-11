#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[50], size,i;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    for (i = 0; i < size ; i++)
    {
        printf("Enter element %d - ",i);
        scanf("%d",&arr[i]);
    }
    bubblesort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}