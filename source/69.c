#include<stdio.h>

int mySqrt(int x){
    if(x==0)return 0;
    if(x<4)return 1;
    else{
        int left=2;
        int right=x/2+1;
        while(left<right){
            int mid=(left+right)/2;
            if(x/mid>=mid){
                if(x/(mid+1)<(mid+1))return mid;
                left=mid;
            }
            else right=mid;
        }
        return left;
    }
}
// int search(int left,int right,int x){
//     int mid=(left+right)/2;
//     if(x/mid>=mid){
//         if(x/(mid+1)<(mid+1))return mid;
//         else return search(mid,right,x);
//     }
//     else return search(left,mid,x);
// }
// int mySqrt(int x){
//     if(x==0)return 0;
//     else if(x<4)return 1;
//     else return search(2,x/2+1,x);
// }
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",mySqrt(n));
    return 0;
}