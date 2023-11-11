#include <stdio.h>
int binS(int a[], int l, int h, int v)
{
    if (h >= l)
    {
        int mid = l + (h-l) / 2;
        if (v == a[mid])
        {
            return mid;
        }
        else if (a[mid] > v)
        {
            binS(a, l, mid - 1, v);
        }
        else
        {
            binS(a, mid + 1, h, v);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int a[100],n,search;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l = 0;
    int h = n-1;
    printf("Enter any element: ");
    scanf("%d", &search);
    int m = binS(a, l, h, search);
    if (m == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at %d index", m);
    }
    return 0;
}