#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{false,true} bool;
void printboard(char** board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%c\t",board[i][j]);
        }
        printf("\n");
    }
    return;
}

void printboardint(int board[]){
    for(int i=0;i<9;i++){
            printf("%d\t",board[i]);
    }
    return;
}
int backtrace(char** board,int pos,int spacesize,int space1[],int space2[],int row[9][9],int col[9][9],int block[3][3][9]){
    if(pos==spacesize){
        return 1;
    }
    else{
        int i=space1[pos],j=space2[pos];
        for(int k=0;k<9;k++){
            if(!row[i][k]&&!col[j][k]&&!block[i/3][j/3][k]){
                row[i][k]=col[j][k]=block[i/3][j/3][k]=true;
                board[i][j]=k+'0'+1;
                if(backtrace(board,pos+1,spacesize,space1,space2,row,col,block))return 1;
                else{
                    row[i][k]=col[j][k]=block[i/3][j/3][k]=false;
                    board[i][j]='.';
                }
            }
        }
        return 0;
    }

}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][9];
    int col[9][9];
    int block[3][3][9];
    int spacesize=0;
    int space1[81];
    int space2[81];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    memset(block,false,sizeof(block));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'&&spacesize<81){
                space1[spacesize]=i;
                space2[spacesize]=j;
                spacesize++;
            }
            else if(board[i][j]>='1'&&board[i][j]<='9'){
                int temp=board[i][j]-'0'-1;
                row[i][temp]=col[j][temp]=block[i/3][j/3][temp]=true;
            }
        }
    }
    backtrace(board,0,spacesize,space1,space2,row,col,block);
    return;
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
    printboard(board);
    solveSudoku(board,boardSize,boardColSize);
    printf("solve:\n");
    printboard(board);
    return 0;
}