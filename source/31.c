#include<stdio.h>
#include<stdlib.h>
void nextPermutation(int* nums, int numsSize){
    int right=numsSize-1;
    while(right>0&&nums[right]<=nums[right-1])right--;
    for(int i=0;i<(numsSize-right)/2;i++){
        int temp=nums[right+i];
        nums[right+i]=nums[numsSize-1-i];
        nums[numsSize-1-i]=temp;
    }
    if(right==0)return;
    int left=right-1;
    while(right<numsSize-1&&nums[right]<=nums[left])right++;
    int temp=nums[right];
    nums[right]=nums[left];
    nums[left]=temp;
    return;
}

int main(){
    int numSize;
    scanf("%d",&numSize);
    int *nums=(int*)malloc(sizeof(int)*numSize);
    for(int i=0;i<numSize;i++)scanf("%d",&nums[i]);
    nextPermutation(nums,numSize);
    for(int i=0;i<numSize;i++)printf("%d ",nums[i]);
    return 0;
}