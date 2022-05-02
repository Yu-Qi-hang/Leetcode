#include<stdio.h>
#include<stdlib.h>
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **matrix=(int**)malloc(sizeof(int*)*n);
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    int col=0,k=1;
    for(int i=0;i<n;i++){
        matrix[i]=(int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i]=n;
    }
    for(int i=0;i<(n+1)/2;i++){
        for(int j=col;j<n-col;j++)matrix[i][j]=k++;
        if(i>=n/2)break;
        for(int y=i+1;y<n-i;y++)matrix[y][n-col-1]=k++;
        if(col>=n/2)break;
        for(int x=n-col-2;x>=col;x--)matrix[n-i-1][x]=k++;
        for(int z=n-i-2;z>i;z--)matrix[z][col]=k++;
        col++;
        if(col>=(n+1)/2)break;
    }
    *returnSize=n;
    return matrix;
}
int main(){
    int n;
    int returnSize[1]={0};
    int **returnColSizes;
    scanf("%d",&n);
    int **matrix=generateMatrix(n,returnSize,returnColSizes);
    for(int i=0;i<*returnSize;i++){
        for(int j=0;j<(*returnColSizes)[i];j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}