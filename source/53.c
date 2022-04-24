#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize){

}
int main(){
    int numsSize;
    scanf("%d",&numsSize);
    int *nums=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)scanf("%d",&nums[i]);
    printf("%d",maxSubArray(nums,numsSize));
    return 0;
}