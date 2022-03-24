#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10001
#define bool int
#define false 0
#define true 1

bool isValid(char * s);
int main(){
    char read[MAX];
    memset(read,0,MAX);
    scanf("%s",&read);
    if(isValid(read))printf("true");
    else printf("false");
    return 0;
}

bool isValid(char * s){
    bool ret=true;
    int length=strlen(s);
    if(length%2)return false;
    char *stack=(char*)malloc(sizeof(char)*length);
    int idx=0,i=0;
    while(i<length){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stack[idx]=s[i];
            idx++;
            i++;
        }
        else{
            if(idx<=0){ret=false;break;}
            if(s[i]==')'){
                if(stack[--idx]!='('){ret=false;break;}
                else i++;
            }
            else if(s[i]==']'){
                if(stack[--idx]!='['){ret=false;break;}
                else i++;
            }
            else{
                if(stack[--idx]!='{'){ret=false;break;}
                else i++;
            }
        }
    }
    free(stack);
    if(ret&&idx==0)return true;
    else return false;
}