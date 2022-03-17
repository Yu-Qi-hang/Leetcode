#include<stdio.h>
#include<stdlib.h>
#define MAX 105
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(){
    int *num;
    int Size;
    int tar;
    int *reSize=(int*)malloc(sizeof(int));
    scanf("%d",&Size);
    num=(int *)malloc(sizeof(int)*Size);
    for(int i=0;i<Size;i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&tar);
    int *ret;
    ret=twoSum(num,Size,tar,reSize);
    for(int i=0;i<*reSize-1;i++)
        printf("%d,",ret[i]);
    printf("%d",ret[*reSize-1]);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (numsSize==0)return NULL;
    for(int i=0;i<numsSize-1;i++){
        if(nums[numsSize-1]+nums[i]==target){
            int *result=(int*)malloc(sizeof(int)*2);
            result[0]=i;
            result[1]=numsSize-1;
            *returnSize=2;
            return result;
        }
    }
    return twoSum(nums,numsSize-1,target,returnSize);
}