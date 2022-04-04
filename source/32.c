#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int longestValidParentheses(char * s){
    int stack=0,idx=0;
    int slen=strlen(s);
    while(s[idx]==')'&&idx<slen)idx++;
    if(idx==slen)return 0;
    int head=idx;//the first "("
    while(s[idx]=='('&&idx<slen)idx++;//the first ")"
    if(idx==slen)return 0;
    stack=idx-1;
    while(idx<slen){
        if(s[stack]=='('&&s[idx]==')'){
            s[stack]=s[idx]='0';
            idx++;
            while(s[idx]=='('&&idx<slen)idx++;//the first ")"
            if(idx==slen)break;
            if(s[idx-1]=='(')stack=idx-1;
            else{
                while(stack>=head&&s[stack]=='0')stack--;
            }
        }
        if(stack<head){            
            while(s[idx]==')'&&idx<slen)idx++;//the first ")"
            if(idx==slen)break;
            head=idx;
            while(s[idx]=='('&&idx<slen)idx++;//the first ")"
            if(idx==slen)break;
            stack=idx-1;
        }
    }
    int temp=0,max_len=0;
    for(int i=0;i<slen;i++){
        if(s[i]=='0')temp++;
        else{
            if(max_len<temp)max_len=temp;
            temp=0;
        }
    }
    if(max_len<temp)max_len=temp;
    return max_len;
}
int main(){
    char *input=(char*)malloc(sizeof(char)*30001);
    scanf("%s",input);
    input=(char*)realloc(input,sizeof(char)*(strlen(input)+1));
    printf("%s\n",input);
    printf("%d\n",longestValidParentheses(input));
    printf("%s",input);
    return 0;
}