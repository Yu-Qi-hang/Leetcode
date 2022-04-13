#include<stdio.h>

// int area(int* height, int left,int right){
//     // if(left>=right-1)return 0;
//     int pivot=left+1;
//     for(int i=left+2;i<right;i++){
//         if(height[i]>height[pivot])pivot=i;
//     }
//     int cm=(height[left]<height[right])?height[left]:height[right];
//     if(height[pivot]<cm){
//         int sum=0;
//         for(int i=left+1;i<right;i++){
//             sum+=cm-height[i];
//         }
//         return sum;
//     }
//     else{
//         int a,b;
//         if(left>=pivot-1)a=0;
//         else a=area(height,left,pivot);
//         if(pivot>=right-1)b=0;
//         else b=area(height,pivot,right);
//         return a+b;
//     }
// }

// int trap(int* height, int heightSize){
//     if(heightSize<=2)return 0;
//     int left=0,right=heightSize-1;
//     while(left<right&&height[left]<=height[left+1])left++;
//     while(left<right&&height[right]<=height[right-1])right--;
//     if(left>=right-1)return 0;
//     return area(height,left,right);
// }
int trap(int* height, int heightSize){
    int sum=0,left=0,right=heightSize-1;
    while(left<right&&height[left]<=height[left+1])left++;
    while(left<right&&height[right]<=height[right-1])right--;
    int lefth=height[left],righth=height[right];
    while(left<right){
        if(lefth<=righth){
            while(height[left]<=lefth&&left<right){
                sum+=lefth-height[left++];
            }
            lefth=height[left];
        }
        if(righth<=lefth){
            while(height[right]<=righth&&left<right){
                sum+=righth-height[right--];
            }
            righth=height[right];
        }
    }
    return sum;
}
int main(){
    int height[]={0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d",trap(height,sizeof(height)/sizeof(int)));
    return 0;
}