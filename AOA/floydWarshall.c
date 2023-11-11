#include <stdio.h>
#define MAX 9999

int mindist(int d[4][4],int p[4][4],int i,int j,int k)
{
    p[i][j]=d[i][j]<(d[i][k]+d[k][j]) ? p[i][j] : k;
    return d[i][j]<(d[i][k]+d[k][j]) ? d[i][j] : (d[i][k]+d[k][j]);
}


void apsp(int d[4][4],int p[4][4],int n,int k)
{
    if(k!=n)
    {
        printf("\n");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                printf("%d ",p[i][j]);
            }printf("\n");
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && i!=k && j!=k)
                {d[i][j]=mindist(d,p,i,j,k);}
            }
        }
        
        // printf("%d ",k);
        apsp(d,p,n,k+1);
    }
}

void main()
{
    int d[4][4]={{0,3,MAX,7},{8,0,2,MAX},{5,MAX,0,1},{2,MAX,MAX,0}};
    int p[4][4]={{-1,0,-1,0},{1,-1,1,-1},{2,-1,-1,2},{3,-1,-1,-1}};
    apsp(d,p,4,0);
    printf("\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",p[i][j]);
        }printf("\n");
    }
    // printf("%d",mindist(d,p,1,2,0));
}