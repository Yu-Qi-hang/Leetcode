#include<stdio.h>
#define bool int
#define false 0
#define true 1
bool isPalindrome(int x);
int main(){
    int in;
    scanf("%d",&in);
    if(isPalindrome(in))printf("true");
    else printf("false");
    return 0;
}

bool isPalindrome(int x){
    if(x<0)return false;
    int y=0;
    while(y<x){
        y=y*10+x%10;
        x=x/10;
        if(y==0)return false;
    }
    if(x==y||y/10==x)return true;
    else return false;
}