#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target){
    if(numsSize==0)return 0;
    int idx=0;
    while(idx<numsSize&&nums[idx]<target)idx++;
    return idx;
}
int main(){
    int target=7;
    int nums[]={1,3,5,6};
    int returnSize[]={0};
    printf("%d",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    return 0;
}