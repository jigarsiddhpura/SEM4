#include<stdio.h>
#include<limits.h>
#include<string.h>
#define SIZE 50
int ch[SIZE][SIZE],dir[SIZE][SIZE];

void LCS(char str1[], char str2[]){
    int i,j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for ( i = 1; i < len1; i++)
    {
        ch[i][0] = 0;
    }
    for ( i = 0; i < len2; i++)
    {
        ch[0][i] = 0;
    }

    for ( i = 1; i <= len1; i++)
    {
        for ( j = 1; j <= len2; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                ch[i][j] = ch[i-1][j-1] + 1;
                dir[i][j] = -1;                  // -1 means diagonal
            }
            else if(ch[i-1][j] > ch[i][j-1]){
                ch[i][j] = ch[i-1][j];
                dir[i][j] = -2;                   // -2 means up
            }
            else{
                ch[i][j] = ch[i][j-1];
                dir[i][j] = -3;                  // -3 means left
            }
            
        }  
    }

}

void processLCS(char str1[],int i, int j, int n, int ans[]){
    if(dir[i][j] == -1){
        ans[n-1] = str1[i-1];
        return processLCS(str1,i-1,j-1,n-1,ans);
    }
    else if(dir[i][j] == -2){
        return processLCS(str1,i-1,j,n,ans);
    }
    else if(dir[i][j] == -3){
        return processLCS(str1,i,j-1,n,ans);
    }
    else{
        return ;
    }
}

int main(){
    char str1[SIZE], str2[SIZE];
    int commonSubseq[SIZE];
    printf("Enter str1 : ");
    scanf("%s",&str1);
    printf("Enter str2 : ");
    scanf("%s",&str2);

    if(strcmp(str1,str2)==0){
        printf("str1 and str2 are same.\n");
    }
    else{
        LCS(str1,str2);
        int subSeqlen = ch[strlen(str1)][strlen(str2)];
        processLCS(str1,strlen(str1),strlen(str2),subSeqlen,commonSubseq);
        for (int i = 0; i < subSeqlen; i++)
        {
            printf("%c", commonSubseq[i]);
        }
        
    }
    return 0;

}