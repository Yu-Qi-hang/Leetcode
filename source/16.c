#include<stdio.h>
#define MAX 1000
int threeSumClosest(int* nums, int numsSize, int target);
int absub(int a,int b){
    return (a>b)?a-b:b-a;
}
int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
    int n,target;
    int nums[MAX]={0};
    scanf("%d %d",&n,&target);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    printf("%d",threeSumClosest(nums,n,target));
    return 0;
}

// int threeSumClosest(int* nums, int numsSize, int target){
//     int ret=nums[0]+nums[1]+nums[2];
//     if(numsSize==3)return ret;
//     else{
//         for(int left=1;left<numsSize-1;left++)
//             for(int right=left+1;right<numsSize;right++){
//                 int temp=nums[0]+nums[left]+nums[right];
//                 if(absub(temp,target)<absub(ret,target))ret=temp;
//             }
//         int other=threeSumClosest(&nums[1],numsSize-1,target);
//         if(absub(other,target)<absub(ret,target))ret=other;
//         return ret;
//     }
// }

int threeSumClosest(int* nums, int numsSize, int target){
    int ret=nums[0]+nums[1]+nums[2];
    if(numsSize==3)return ret;
    else{
        int left=1,right=numsSize-1;
        while(left<right){
            int temp=nums[0]+nums[left]+nums[right];
            if(absub(temp,target)<absub(ret,target)){
                ret=temp;
                while(nums[left]==nums[++left]&&left<right);
                while(nums[right]==nums[--right]&&left<right);
            }
            else if(nums[0]+nums[left]+nums[right]<0)left++;
            else right--;
        }
        int other=threeSumClosest(&nums[1],numsSize-1,target);
        if(absub(other,target)<absub(ret,target))ret=other;
        return ret;
    }
}