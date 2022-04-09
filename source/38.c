#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char * countAndSay(int n){
    if(n==1){
        char *ret=(char*)malloc(sizeof(char)*2);
        memset(ret,0,2);
        ret[0]='1';
        return ret;
    }
    char *temp=countAndSay(n-1);
    int len=strlen(temp);
    char *sum=malloc(sizeof(char));
    char *sub=malloc(sizeof(char)*2);
    char *num=malloc(sizeof(char)*2);
    int cnt=0;
    int idx=0;
    memset(sum,0,1);
    memset(sub,0,2);
    memset(num,0,2);
    while(idx<len){
        cnt=0;
        sub[0]=temp[idx];
        while(temp[idx]==sub[0]){
            cnt++;
            idx++;
        }
        sum=(char*)realloc(sum,sizeof(char)*(strlen(sum)+3));
        num[0]=cnt+'0';
        strcat(sum,num);
        strcat(sum,sub);
    }
    free(temp);
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%s",countAndSay(n));
    return 0;
}