#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void main()

{

    int a[50], n, i, key;

    printf("Enter Size of Array:");

    scanf("%d", &n);

    printf("Enter Array Element:");

    for (i = 0; i < n; i++)

        scanf("%d", &a[i]);

    printf("Array:\n");

    for (i = 0; i < n; i++)

        printf("%d\n", a[i]);

    printf("Enter Key To Search:");

    scanf("%d", &key);

    sentinelsearch(a, n, key);
}

sentinelsearch(int a[], int n, int key)

{

    int i, last;

    last = a[n - 1];

    a[n - 1] = key;

    i = 0;

    while (a[i] != key)

        i++;

    a[n - 1] = last;

    if (a[i] == key)

    {

        printf("Search found at index %d", i );
    }

    else

    {

        printf("Not found");
    }
}