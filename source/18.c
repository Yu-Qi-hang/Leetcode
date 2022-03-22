#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a, const void * b);
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);
int main(){
    int target=8;
    int nums[]={2,2,2,2,2};
    int returnSize[]={0};
    int **returnColumnSizes;
    int **tuple;
    tuple=fourSum(nums,sizeof(nums)/sizeof(int),target,returnSize,returnColumnSizes);
    for(int i=0;i<*returnSize;i++)
        printf("%d %d %d %d\n",tuple[i][0],tuple[i][1],tuple[i][2],tuple[i][3]);
    return 0;
}

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int batch=8;
    int **ret=(int**)malloc(sizeof(int*)*batch);
    *returnColumnSizes=(int *)malloc(sizeof(int)*batch);
    int returnsize=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int idx1,idx2,idx3,idx4;
    for(idx1=0;idx1<numsSize-3;idx1++){
        if(nums[idx1]>target&&nums[idx1]>=0)break;
        if(idx1>0&&nums[idx1]==nums[idx1-1])continue;
        for(idx2=idx1+1;idx2<numsSize-2;idx2++){
            if(nums[idx1]+nums[idx2]>target&&nums[idx1]>=0)break;
            if(idx2>idx1+1&&nums[idx2]==nums[idx2-1])continue;
            idx3=idx2+1;
            idx4=numsSize-1;
            while(idx3<idx4){
                if(nums[idx4]<=0){
                    if(nums[idx3]+nums[idx4]<target)break;
                    if(nums[idx2]+nums[idx3]+nums[idx4]<target)break;
                }
                else if(nums[idx1]>=0){
                    if(nums[idx1]+nums[idx2]+nums[idx3]>target)break;
                }
                if(nums[idx1]+nums[idx2]+nums[idx3]+nums[idx4]==target){
                    ret[returnsize]=(int *)malloc(sizeof(int)*4);
                    ret[returnsize][0]=nums[idx1];
                    ret[returnsize][1]=nums[idx2];
                    ret[returnsize][2]=nums[idx3];
                    ret[returnsize][3]=nums[idx4];
                    (*returnColumnSizes)[returnsize]=4;
                    (returnsize)+=1;
                    if(returnsize==batch){
                        batch*=2;                        
                        ret=(int**)relloc(ret,sizeof(int*)*batch);
                        *returnColumnSizes=(int *)realloc(*returnColumnSizes,sizeof(int)*batch);
                    }
                    while(nums[idx3]==nums[++idx3]&&idx3<idx4);
                    while(nums[idx4]==nums[--idx4]&&idx3<idx4);
                }
                else if(nums[idx1]+nums[idx2]+nums[idx3]+nums[idx4]<target)idx3++;
                else idx4--;
            }
        }
    }
    *returnSize=returnsize;
    return ret;
}