#include<conio.h>
#include<stdio.h>

void main()
{
    int arr[100],arr2[100],fr[100],i,j,n,ctr,temp;
    printf("Enter the number of elements u wanna enter - ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d - ",i);
        scanf("%d",&arr[i]);
        fr[i]=-1;
        arr2[i]=0;
    }
    
    for(i=0;i<n;i++)
    {   
        ctr=1;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                fr[j]=0;
                ctr++;
            }
        }
        if(fr[i]!=0)
        {
            fr[i]=ctr;
        }
    }

    for(i=0;i<n;i++)
    {
        if(fr[i]!=0){
            printf("frequency of %d is %d\n",arr[i],fr[i]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(arr[i+1]!=arr[i]){
            arr2[i]=arr[i];
        }
    }

    printf("array without duplicates - \n");
    for(i=0;i<n;i++)
    {
        if(arr2[i]!=0)
        {
            printf("%d ",arr2[i]);
        }
    }
}










