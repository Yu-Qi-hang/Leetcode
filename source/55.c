#include<stdio.h>
#include<stdlib.h>
typedef enum{false,true}bool;
bool canJump(int* nums, int numsSize){
    int now=0;
    int max=0;
    while(now<numsSize-1){
        if(nums[now]==0)break;
        max=0;
        for(int i=0;i<=nums[now];i++){
            if(now+i>=numsSize)break;
            if(nums[now+i]+i>=nums[now+max]+max)max=i;
        }
        if(max==0)now+=nums[now];
        else now+=max;
    }
    if(now>=numsSize-1)return true;
    else return false;
}
int main(){
    int numsSize;
    scanf("%d",&numsSize);
    int *nums=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)scanf("%d",&nums[i]);
    if(canJump(nums,numsSize))printf("true");
    else printf("false");
    return 0;
}