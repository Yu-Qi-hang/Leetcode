#include<stdio.h>
#include<math.h>
int dividerecursive(int dividend, int divisor){
    if(dividend<divisor)return 0;
    int ret=1;
    int batch=divisor;
    int new;
    if(dividend>divisor)new=dividend>>1;
    while(batch<new){
        ret=ret<<1;
        batch=batch<<1;
    }
    int cnt=0;
    while(dividend>=batch){
        cnt+=ret;
        dividend-=batch;
    }
    return cnt+dividerecursive(dividend,divisor);
}
int divide(int dividend, int divisor){
    int ret=0;
    if(divisor==-2147483648){
        if(dividend==-2147483648)return 1;
        return 0;
    }
    if(divisor==2147483647){
        if(dividend<=-2147483647)return -1;
        if(dividend==2147483647)return 1;
        return 0;
    }
    if(divisor==-2147483647){
        if(dividend<=-2147483647)return 1;
        if(dividend==2147483647)return -1;
        return 0;
    }
    if(dividend==-2147483648){
        if(divisor==1)return dividend;
        if(divisor==-1)return 2147483647;
        ret++;
        dividend=dividend+abs(divisor);
    }
    int flag=1;
    if(dividend<0){
        dividend=0-dividend;
        flag=0-flag;
    }
    if(divisor<0){
        divisor=0-divisor;
        flag=0-flag;
    }
    ret+=dividerecursive(dividend,divisor);
    if(flag<0)ret=0-ret;
    return ret;
}
int main(){
    int dividend,divisor;
    scanf("%d %d",&dividend,&divisor);
    printf("%d",divide(dividend,divisor));
    return 0;
}