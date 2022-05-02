#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* backtracer(char* now,int k){
    if(k==0)return now;
    else{
        int numsSize=strlen(now);
        int right=numsSize-1;
        while(right>0&&now[right]<=now[right-1])right--;
        for(int i=0;i<(numsSize-right)/2;i++){
            char temp=now[right+i];
            now[right+i]=now[numsSize-1-i];
            now[numsSize-1-i]=temp;
        }
        int left=right-1;
        while(right<numsSize-1&&now[right]<=now[left])right++;
        char temp=now[right];
        now[right]=now[left];
        now[left]=temp;
        return backtracer(now,k-1);
    }
}
char * getPermutation(int n, int k){
    char *ret=(char*)malloc(sizeof(char)*(n+1));
    int i=0;
    for(i=0;i<n;i++){
        ret[i]=i+1+'0';
    }
    ret[i]='\0';
    ret=backtracer(ret,k);
    return ret;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char *per=getPermutation(n,k);
    printf("%s",per);
    return 0;
}