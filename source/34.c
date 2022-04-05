#include<stdio.h>
#include<stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    ret[0]=-1;
    ret[1]=-1;
    if(numsSize==0)return ret;
    if(target<nums[0]||target>nums[numsSize-1])return ret;
    int idx=0;
    while(idx<numsSize){
        if(nums[idx]<target)idx++;
        else break;
    }
    if(nums[idx]!=target)return ret;
    else{
        ret[0]=ret[1]=idx;
    }
    while(idx<numsSize){
        if(nums[idx]==target)idx++;
        else break;
    }
    ret[1]=idx-1;
    return ret;
}

int main(){
    int target=8;
    int nums[]={5,7,7,8,8,10};
    int returnSize[]={0};
    int *tuple=searchRange(nums,sizeof(nums)/sizeof(int),target,returnSize);
    printf("%d %d",tuple[0],tuple[1]);
    return 0;
}