#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
int main(){
    int returnSize[]={0};
    int nums[]={0,0,0,0,0};//修改输入
    int **returnColumnSizes;
    int **tuple;
    tuple=threeSum(nums,sizeof(nums)/sizeof(int),returnSize,returnColumnSizes);
    for(int i=0;i<(*returnSize);i++){
        printf("%d %d %d\n",tuple[i][0],tuple[i][1],tuple[i][2]);
    }
    return 0;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret=(int**)malloc(sizeof(int*)*numsSize*numsSize);
    *returnColumnSizes=(int *)malloc(sizeof(int)*numsSize*numsSize);
    int returnsize=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int idx,left,right;
    for(idx=0;idx<numsSize-2;idx++){
        if(nums[idx]>0)break;
        if(idx>0&&nums[idx]==nums[idx-1])continue;
        left=idx+1;
        right=numsSize-1;
        while(left<right){
            if(nums[idx]+nums[left]+nums[right]==0){
                ret[returnsize]=(int *)malloc(sizeof(int)*3);
                ret[returnsize][0]=nums[idx];
                ret[returnsize][1]=nums[left];
                ret[returnsize][2]=nums[right];
                (*returnColumnSizes)[returnsize]=3;
                (returnsize)+=1;
                while(nums[left]==nums[++left]&&left<right);
                while(nums[right]==nums[--right]&&left<right);/*
                while(nums[left]==nums[left+1]&&left+1<right)left++;
                if(left<right)left++;
                while(nums[right]==nums[right-1]&&left<right-1)right--;
                if(left<right)right--;*/
            }
            else if(nums[idx]+nums[left]+nums[right]<0)left++;
            else right--;
        }
    }
    *returnSize=returnsize;
    return ret;
}