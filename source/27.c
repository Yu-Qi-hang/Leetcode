#include<stdio.h>
#include<stdlib.h>
int removeElement(int* nums, int numsSize, int val){
    int offset=0;
    for(int i=0;i<numsSize;i++){
        if(offset)nums[i]=nums[i+offset];
        while(nums[i]==val){
            offset++;
            if(offset+i<=numsSize-1)nums[i]=nums[i+offset];
            else break;
        }
        if(offset+i>=numsSize-1)break;
    }
    return numsSize-offset;
}

int main(){
    int numsSize;
    scanf("%d",&numsSize);
    int *nums = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)scanf("%d",&nums[i]);
    int val;
    scanf("%d",&val);
    int k = removeElement(nums,numsSize,val);
    for (int i = 0; i < k; i++) {
        printf("%d ",nums[i]);
    }
}