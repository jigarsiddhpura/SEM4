// for sorted arrays
#include <stdio.h>

int binarySearch(int arr[], int x, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        if (x == arr[mid])
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            return binarySearch(arr, x, mid + 1, high);
        }
        else
        {
            return binarySearch(arr, x, low, mid - 1);
        }
    }
    return -1;
}

void main(){
    int arr[50], size,i,x,index;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    for (i = 0; i < size ; i++)
    {
        printf("Enter element %d - ",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&x);
    index = binarySearch(arr, x, 0, size-1);
    if (index == -1){
        printf("Not found");
    }
    else{
    printf("%d is at index %d",x,index);
    }

}

