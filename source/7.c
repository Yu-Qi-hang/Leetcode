#include<stdio.h>
#define MAX 2147483647
#define MIN -2147483648
int reverse(int x);

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",reverse(n));
    return 0;
}
int reverse(int x){
    int flag=1;
    if(x<0)flag=-1;
    int ret=0;
    while (x!=0)
    {
        if(ret<=MAX/10&&ret>=MIN/10)ret=flag*(x%10)+ret*10;
        else return 0;
        x=x/10;
    }
    return flag*ret;
}