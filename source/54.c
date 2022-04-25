#include<stdio.h>
#include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *ret=(int*)malloc(sizeof(int)*matrixSize*matrixColSize[0]);
    int col=0,k=0;
    for(int i=0;i<(matrixSize+1)/2;i++){
        for(int j=col;j<matrixColSize[i]-col;j++)ret[k++]=matrix[i][j];
        if(i>=matrixSize/2)break;
        for(int y=i+1;y<matrixSize-i;y++)ret[k++]=matrix[y][matrixColSize[i]-col-1];
        if(col>=matrixColSize[i]/2)break;
        for(int x=matrixColSize[i]-col-2;x>=col;x--)ret[k++]=matrix[matrixSize-i-1][x];
        for(int z=matrixSize-i-2;z>i;z--)ret[k++]=matrix[z][col];
        col++;
        if(col>=(matrixColSize[0]+1)/2)break;
    }
    *returnSize=k;
    return ret;
}
int main(){
    int matrixSize;
    int col;
    scanf("%d%d",&matrixSize,&col);
    int *matrixColSize=(int*)malloc(sizeof(int)*matrixSize);
    int **matrix=(int**)malloc(sizeof(int*)*matrixSize);
    for(int i=0;i<matrixSize;i++){
        matrixColSize[i]=col;
        matrix[i]=(int*)malloc(sizeof(int)*matrixColSize[i]);
        for(int j=0;j<matrixColSize[i];j++)scanf("%d",&matrix[i][j]);
    }
    int returnSize[1]={0};
    int *queue=spiralOrder(matrix,matrixSize,matrixColSize,returnSize);
    for(int i=0;i<*returnSize;i++)printf("%d ",queue[i]);
    return 0;
}