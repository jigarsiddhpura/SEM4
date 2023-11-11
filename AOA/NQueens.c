#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int position[20];

int Abs(int i)
{
    return i < 0 ? -i : i;
}

bool Place(int row, int column)
{
    for (int j = 0; j < row; j++)
    {
        if ((position[j] == column) || (Abs(position[j] - column) == Abs(j - row))){
            return false;
        }
    }
    return true;
}

void NQueens(int row , int n){
    for (int queen = 0; queen < n; queen++)
    {
        if( Place(row,queen) ){
            position[row] = queen;
            if(row==n-1){
                for (int i = 0; i < n; i++)
                {
                    printf("Queen %d placed at column %d\n",i+1,position[i]+1);
                } 
            printf("\n\n");   
            }
            else{
                NQueens(row+1,n);
            }
        }
    } 
}

void main()
{
    int queensCount ;
    printf("Enter the number of queens : ");
    scanf("%d",&queensCount);
    NQueens(0,queensCount);
}