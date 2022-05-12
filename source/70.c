#include<stdio.h>
int climbStairs(int n){
    if(n==1)return 1;
    int step[n];
    step[0]=1;
    step[1]=2;
    for(int i=2;i<n;i++)step[i]=step[i-1]+step[i-2];
    return step[n-1];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",climbStairs(n));
    return 0;
}