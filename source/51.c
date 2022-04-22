#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char **createboard(int*place,int n){
    char **board=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        board[i]=(char*)malloc(sizeof(char)*(n+1));
        for(int j=0;j<n;j++)board[i][j]='.';
        board[i][place[i]]='Q';
        board[i][n]='\0';
    }
    return board;
}
void Backtrace(char***result,int*place,int n,int row,int *returnSize,int *column,int *diag1,int *diag2){
    if(row==n){
        char **board=createboard(place,n);
        result[*returnSize]=board;
        (*returnSize)++;
    }
    else{
        for(int i=0;i<n;i++){
            if(column[i])continue;
            int diagidx1=row-i+n-1;
            if(diag1[diagidx1])continue;
            int diagidx2=row+i;
            if(diag2[diagidx2])continue;
            place[row]=i;
            column[i]=1;
            diag1[diagidx1]=1;
            diag2[diagidx2]=1;
            Backtrace(result,place,n,row+1,returnSize,column,diag1,diag2);
            place[row]=-1;
            column[i]=0;
            diag1[diagidx1]=0;
            diag2[diagidx2]=0;
        }
    }
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***result=(char***)malloc(sizeof(char**)*501);
    // int *place=(char*)malloc(sizeof(int)*n);
    // int *column=(int*)malloc(sizeof(int)*n);
    // int *diag1=(int*)malloc(sizeof(int)*n*2);
    // int *diag2=(int*)malloc(sizeof(int)*n*2);
    int place[n],column[n],diag1[n+n],diag2[n+n];
    memset(place,-1,sizeof(place));
    memset(column,0,sizeof(column));
    memset(diag1,0,sizeof(diag1));
    memset(diag2,0,sizeof(diag2));
    *returnSize=0;
    Backtrace(result,place,n,0,returnSize,column,diag1,diag2);
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i]=n;
    }
    return result;    
}

int main(){
    int n;
    int returnSize[1]={0};
    int **returnColumnSizes;
    scanf("%d",&n);
    char ***solve=solveNQueens(n,returnSize,returnColumnSizes);
    for(int i=0;i<*returnSize;i++){
        printf("sol%d:\n",i);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                printf("%c ",solve[i][j][k]);
            printf("\n");
        }
    }
    return 0;
}