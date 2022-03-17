#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char * s);
int find(char x,char *s,int start,int end);
int main(){
    char s[50001];
    scanf("%s",&s);
    // printf("%d",strlen(s));
    printf("%d",lengthOfLongestSubstring(s));
    return 0;
}
int find(char x,char *s,int start,int end){
    int ret=-1;
    for(int i=start;i<=end;i++){
        if(x==s[i]){
            ret=i;
            break;
        }
    }
    return ret;
}
int lengthOfLongestSubstring(char * s){
    int length=0;
    int temp=0;
    int a=0,b=0;
    while(b<strlen(s)){
        b++;
        if(find(s[b],s,a,b-1)==-1){
            temp=b-a;
            length=(temp>length)?temp:length;
        }
        else{
            a=1+find(s[b],s,a,b-1);
            temp=b-a;
            length=(temp>length)?temp:length;
        }
    }
    return length;
}

