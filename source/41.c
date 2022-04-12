#include<stdio.h>
#include<stdlib.h>

int firstMissingPositive(int* nums, int numsSize){
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]<=0)nums[i]=numsSize+1;
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]>=1&&nums[i]<=numsSize){
            int idx=nums[i]-1;
            nums[idx]=nums[idx]<0?nums[idx]:-1*nums[idx];
        }
        if(nums[i]<=-1&&nums[i]>=-1*numsSize){
            int idx=-1*nums[i]-1;
            nums[idx]=nums[idx]<0?nums[idx]:-1*nums[idx];
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]>0)return i+1;
    }
    return numsSize+1;
}

int main(){
    int numsSize;
    scanf("%d",&numsSize);
    int *nums=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)scanf("%d",&nums[i]);
    printf("%d",firstMissingPositive(nums,numsSize));
    return 0;
}