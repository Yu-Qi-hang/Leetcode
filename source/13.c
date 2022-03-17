#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int romanToInt(char * s);
int main(){
    char s[16];
    memset(s,0,16);
    scanf("%s",&s);
    printf("%d",romanToInt(s));
    return 0;
}
int romanToInt(char * s){
    int idx=0;
    int ret=0;
    while(s[idx]=='M'){
        ret+=1000;
        idx++;
    }
    if(s[idx]=='C'){
        if(s[idx+1]=='M'){
            ret+=900;
            idx+=2;
        }
        else if(s[idx+1]=='D'){
            ret+=400;
            idx+=2;
        }
    }
    else if(s[idx]=='D'){
        ret+=500;
        idx++;
    }
    while(s[idx]=='C'){
        ret+=100;
        idx++;
    }
    if(s[idx]=='X'){
        if(s[idx+1]=='C'){
            ret+=90;
            idx+=2;
        }
        else if(s[idx+1]=='L'){
            ret+=40;
            idx+=2;
        }
    }
    else if(s[idx]=='L'){
        ret+=50;
        idx++;
    }
    while(s[idx]=='X'){
        ret+=10;
        idx++;
    }
    if(s[idx]=='I'){
        if(s[idx+1]=='X'){
            ret+=9;
            idx+=2;
        }
        else if(s[idx+1]=='V'){
            ret+=4;
            idx+=2;
        }
    }
    while(s[idx]=='V'){
        ret+=5;
        idx++;
    }
    while(s[idx]=='I'){
        ret+=1;
        idx++;
    }
    return ret;
}