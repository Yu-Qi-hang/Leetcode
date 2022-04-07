#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{false,true} bool;
int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int checkline(int *test,int n){
    qsort(test,n,sizeof(int),cmp);
    for(int i=0;i<n-1;i++){
        if(test[i]==test[i+1])return 0;
    }
    return 1;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    *boardColSize=boardSize;
    int *queue=(int*)malloc(sizeof(int)*9);
    int idx=0;
    for(int i=0;i<9;i++){
        memset(queue,0,9);
        idx=0;
        for(int j=0;j<9;j++){
            if(board[i][j]>='1'&&board[i][j]<='9'){
                queue[idx++]=board[i][j]-'0';
            }
        }
        if(!checkline(queue,idx))return false;
    }
    for(int i=0;i<9;i++){
        memset(queue,0,9);
        idx=0;
        for(int j=0;j<9;j++){
            if(board[j][i]>='1'&&board[j][i]<='9'){
                queue[idx++]=board[j][i]-'0';
            }
        }
        if(!checkline(queue,idx))return false;
    }
    for(int row=0;row<9;row+=3){
        for(int clo=0;clo<9;clo+=3){
            memset(queue,0,9);
            idx=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[row+i][clo+j]>='1'&&board[row+i][clo+j]<='9'){
                        queue[idx++]=board[row+i][clo+j]-'0';
                    }
                }
                if(!checkline(queue,idx))return false;
            }
        }
    }
    return true;
}
int main(){
    char **board=(char**)malloc(sizeof(char*)*9);
    int boardSize=9;
    int boardColSize[]={0};
    for(int i=0;i<9;i++){
        board[i]=(char*)malloc(sizeof(char)*10);
        memset(board[i],0,10);
        scanf("%s",board[i]);
    }
    printf("%d",isValidSudoku(board,boardSize,boardColSize));
    // for(int i=0;i<9;i++){
    //     printf("%s\n",board[i]);
    // }
    return 0;
}