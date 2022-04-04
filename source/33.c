#include<stdio.h>
#include<stdlib.h>

int search(int* nums, int numsSize, int target){
    int re;
    if(target>=nums[0]){
        int i=0;
        re=nums[0];
        while(nums[i]>=re&&nums[i]<target&&i<numsSize-1)i++;
        if(nums[i]==target)return i;
    }
    else if(target<=nums[numsSize-1]){
        int i=numsSize-1;
        re=nums[numsSize-1];
        while(nums[i]<=re&&nums[i]>target&&i>0)i--;
        if(nums[i]==target)return i;
    }
    return -1;
}
int main(){
    int numsSize,target;
    scanf("%d %d",&numsSize,&target);
    int *nums=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)scanf("%d",&nums[i]);
    // for(int i=0;i<numsSize;i++)printf("%d ",nums[i]);
    printf("%d",search(nums,numsSize,target));
    return 0;
}