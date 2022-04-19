#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void printmatrix(int len,int**matrix){
    printf("matrix:\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)printf("%d ",matrix[i][j]);
        printf("\n");
    }
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i=0;i<matrixSize/2;i++){
        for(int j=i;j<matrixSize-1-i;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[matrixSize-1-j][i];
            matrix[matrixSize-1-j][i]=matrix[matrixSize-1-i][matrixSize-1-j];
            matrix[matrixSize-1-i][matrixSize-1-j]=matrix[j][matrixSize-1-i];
            matrix[j][matrixSize-1-i]=temp;
        }
    }
    *matrixColSize=matrixSize;
    return;
}

int main(){
    int len;
    int *matrixColSize=malloc(sizeof(int));
    scanf("%d",&len);
    int **matrix=(int**)malloc(sizeof(int*)*len);
    for(int i=0;i<len;i++){
        matrix[i]=(int*)malloc(sizeof(int)*len);
        for(int j=0;j<len;j++)scanf("%d",&matrix[i][j]);
    }
    printmatrix(len,matrix);
    rotate(matrix,len,matrixColSize);
    printmatrix(len,matrix);
    return 0;
}