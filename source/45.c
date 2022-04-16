#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int jump(int* nums, int numsSize){
//     printf("size:%d\n",numsSize);
//     if(numsSize==1)return 0;
//     if(nums[0]>=numsSize-1)return 1;
//     int min=numsSize;
//     for(int i=1;i<=nums[0];i++){
//         if(jump(&nums[i],numsSize-i)<min)min=jump(&nums[i],numsSize-i);
//     }
//     return min+1;
// }
int jump(int* nums, int numsSize){
    if(numsSize==1)return 0;
    if(nums[0]>=numsSize-1)return 1;
    int max=0;
    int idx=0;
    for(int i=1;i<=nums[0];i++){
        if(i+nums[i]>max){
            max=i+nums[i];
            idx=i;
        }
    }
    return 1+jump(&nums[idx],numsSize-idx);
}
int main(){
    int nums[]={2,3,0,1,4};
    printf("%d",jump(nums,sizeof(nums)/sizeof(int)));
    return 0;
}