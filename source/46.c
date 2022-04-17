#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int * nums,int indexA,int indexB)
{
    int temp=nums[indexA];
    nums[indexA]=nums[indexB];
    nums[indexB]=temp;
}
void BackTrace(int **result,int layer,int idx,int *returnSize,int *nums,int *col){
    if(idx==layer){
        result[*returnSize]=(int*)malloc(sizeof(int)*layer);
        memcpy(result[*returnSize],nums,layer*sizeof(int));
        col[*returnSize]=layer;
        (*returnSize)++;
        return;
    }
    else{
        for(int i=idx;i<layer;i++){
            swap(nums,idx,i);
            BackTrace(result,layer,idx+1,returnSize,nums,col);
            swap(nums,idx,i);
        }
        return;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int sum=1;
    for(int i=1;i<=numsSize;i++)sum*=i;
    int **ret=(int**)malloc(sizeof(int*)*sum);
    *returnColumnSizes=(int*)malloc(sizeof(int)*sum);
    *returnSize=0;
    BackTrace(ret,numsSize,0,returnSize,nums,*returnColumnSizes);
    return ret;
}
int main(){
    int nums[]={2,3,6,7};
    int returnSize[]={0};
    int **returnColumnSizes;
    int **ret=permute(nums,sizeof(nums)/sizeof(int),returnSize,returnColumnSizes);
    int n=*returnSize;
    for(int i=0;i<n;i++){
        int m=(*returnColumnSizes)[i];
        for(int j=0;j<m;j++)
            printf("%d ",ret[i][j]);
        printf("\n");
    }
    return 0;
}