#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Backtrace(int*place,int n,int row,int *returnSize,int *column,int *diag1,int *diag2){
    if(row==n){
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
            Backtrace(place,n,row+1,returnSize,column,diag1,diag2);
            place[row]=-1;
            column[i]=0;
            diag1[diagidx1]=0;
            diag2[diagidx2]=0;
        }
    }
}
int totalNQueens(int n){
    int place[n],column[n],diag1[n+n],diag2[n+n];
    memset(place,-1,sizeof(place));
    memset(column,0,sizeof(column));
    memset(diag1,0,sizeof(diag1));
    memset(diag2,0,sizeof(diag2));
    int returnSize[1]={0};
    Backtrace(place,n,0,returnSize,column,diag1,diag2);
    return *returnSize;      
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",totalNQueens(n));
    return 0;
}