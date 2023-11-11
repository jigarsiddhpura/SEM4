#include <stdio.h>

int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
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
    index = search(arr, size, x);
    if (index == -1){
        printf("Not found");
    }
    else{
    printf("%d is at index %d",x,index);
    }
}