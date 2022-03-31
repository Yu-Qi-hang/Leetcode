#include<stdio.h>
#include<string.h>
#define MAX 50001
int mystrStr(char * haystack, char * needle){
    if(needle[0]=='\0')return 0;
    int ret=0;
    while(haystack[ret]!='\0'){
        if(haystack[ret]==needle[0]){
            if(strncmp(&haystack[ret],needle,strlen(needle))==0)
                return ret;
        }
        ret++;
    }
    return -1;
}
int main(){
    char hay[MAX],need[MAX];
    memset(hay,0,MAX);
    memset(need,0,MAX);
    scanf("%s",hay);
    scanf("%s",need);
    printf("%d",mystrStr(hay,need));
    return 0;
}