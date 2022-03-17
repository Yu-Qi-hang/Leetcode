#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1001

char * convert(char * s, int numRows);

int main(){
    int numRows;
    char s[MAX];
    memset(s,0,MAX);
    scanf("%d",&numRows);
    scanf("%s",&s);
    printf("%s",convert(s,numRows));
    return 0;
}

char * convert(char * s, int numRows){
    if(numRows==1)return s;
    int step=(numRows-1)*2;
    char *ret=(char*)malloc(sizeof(char)*MAX);
    memset(ret,0,MAX);
    int i=0,j=0,start=0,nap=step;
    for(start=0;start<=step/2;start++){
        nap=step-start;
        for(i=start;i<strlen(s);i+=step){
            ret[j++]=s[i];
            if(nap<step&&nap>step/2&&i+nap-start<strlen(s))ret[j++]=s[i+nap-start];
        }
    }
    ret[j]='\0';
    return ret;
}